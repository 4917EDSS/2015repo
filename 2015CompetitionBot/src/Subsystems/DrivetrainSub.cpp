#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "RobotParameters.h"

// PID Parameters
#ifdef PRACTICE_BOT
	// Encoder values (millimeters/tick)
	#define RIGHT_DISTANCE_PER_PULSE (2000.0/7920.0)
	#define LEFT_DISTANCE_PER_PULSE (2000.0/7920.0)

	// PID parameters
	#define SPEED_P_VALUE 0.0005
	#define SPEED_I_VALUE 0
	#define SPEED_D_VALUE 0
	#define SPEED_F_VALUE 0

	#define AUTO_SPEED_P_VALUE 0.0015
	#define AUTO_SPEED_I_VALUE 0
	#define AUTO_SPEED_D_VALUE 0
	#define AUTO_SPEED_F_VALUE 0

	#define DISTANCE_P_VALUE 0.04
	#define DISTANCE_I_VALUE 0.0
	#define DISTANCE_D_VALUE 0.1
	#define DISTANCE_F_VALUE 0

#else // COMPETITION_BOT
	// Encoder values (millimeters/tick)
	#define RIGHT_DISTANCE_PER_PULSE (2000.0/11250.0)
	#define LEFT_DISTANCE_PER_PULSE (2000.0/11250.0)

	#define SPEED_P_VALUE 0.00038
	#define SPEED_I_VALUE 0
	#define SPEED_D_VALUE 0
	#define SPEED_F_VALUE 0

	#define AUTO_SPEED_P_VALUE 0.0011
	#define AUTO_SPEED_I_VALUE 0
	#define AUTO_SPEED_D_VALUE 0
	#define AUTO_SPEED_F_VALUE 0

	#define DISTANCE_P_VALUE 0.035
	#define DISTANCE_I_VALUE 0.0
	#define DISTANCE_D_VALUE 0.04
	#define DISTANCE_F_VALUE 0

#endif

// PID set-point tolerances
#define DRIVE_DIST_TOLERANCE 30			// in mm
#define DRIVE_TURN_TOLERANCE 10
#define SPEED_TOLERANCE 20				// in mm/s
#define AUTO_SPEED_TOLERANCE 130		// in mm/s


DrivetrainSub::DrivetrainSub(int rightMotorC, int leftMotorC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C) :
		Subsystem("DrivetrainSub")
{
	rightMotor = new Talon(rightMotorC);
	leftMotor = new Talon(leftMotorC);
	leftSpeedVirtualEncoder = new Encoder4917(leftEncoder1C, leftEncoder2C);
	rightSpeedVirtualEncoder = new Encoder4917(rightEncoder1C, rightEncoder2C);
	leftDistanceEncoder  = leftSpeedVirtualEncoder->GetEncoder();
	rightDistanceEncoder = rightSpeedVirtualEncoder->GetEncoder();

	controlState = TANK_DRIVE_CONTROLS;
	pidGetSetId = NORMAL_SPEED_CTRL_ID;

	// Set encoder parameters
	leftDistanceEncoder->SetDistancePerPulse(LEFT_DISTANCE_PER_PULSE*ENCODER_CONVERSION_FACTOR);
	rightDistanceEncoder->SetDistancePerPulse(RIGHT_DISTANCE_PER_PULSE*ENCODER_CONVERSION_FACTOR);

	// Set PID controller parameters
	// Speed is calculated from the distance encoders
	// There are two speed PID pairs since we need different values for driving (FPS-mode) and auto
	leftDriveSpeedController = new PIDController(SPEED_P_VALUE, SPEED_I_VALUE, SPEED_D_VALUE, SPEED_F_VALUE, leftSpeedVirtualEncoder, leftMotor);
	rightDriveSpeedController = new PIDController(SPEED_P_VALUE, SPEED_I_VALUE, SPEED_D_VALUE, SPEED_F_VALUE, rightSpeedVirtualEncoder, rightMotor);
	leftDriveSpeedController->SetAbsoluteTolerance(SPEED_TOLERANCE);
	rightDriveSpeedController->SetAbsoluteTolerance(SPEED_TOLERANCE);
	leftDriveSpeedController->SetOutputRange(-1.0, 1.0);
	rightDriveSpeedController->SetOutputRange(-1.0, 1.0);
	leftDriveSpeedController->Disable();
	rightDriveSpeedController->Disable();

	leftAutoSpeedController = new PIDController(AUTO_SPEED_P_VALUE, AUTO_SPEED_I_VALUE, AUTO_SPEED_D_VALUE, AUTO_SPEED_F_VALUE, leftSpeedVirtualEncoder, leftMotor);
	rightAutoSpeedController = new PIDController(AUTO_SPEED_P_VALUE, AUTO_SPEED_I_VALUE, AUTO_SPEED_D_VALUE, AUTO_SPEED_F_VALUE, rightSpeedVirtualEncoder, rightMotor);
	leftAutoSpeedController->SetAbsoluteTolerance(AUTO_SPEED_TOLERANCE);
	rightAutoSpeedController->SetAbsoluteTolerance(AUTO_SPEED_TOLERANCE);
	leftDriveSpeedController->SetOutputRange(-1.0, 1.0);
	rightDriveSpeedController->SetOutputRange(-1.0, 1.0);
	leftAutoSpeedController->Disable();
	rightAutoSpeedController->Disable();

	// Set current speed control mode to normal driving
	leftCurSpeedController = leftDriveSpeedController;
	rightCurSpeedController = rightDriveSpeedController;

	// Distance PID setup
	leftDistanceController = new PIDController(DISTANCE_P_VALUE, DISTANCE_I_VALUE, DISTANCE_D_VALUE, DISTANCE_F_VALUE, leftDistanceEncoder, leftMotor);
	rightDistanceController = new PIDController(DISTANCE_P_VALUE, DISTANCE_I_VALUE, DISTANCE_D_VALUE, DISTANCE_F_VALUE, rightDistanceEncoder, rightMotor);
	leftDistanceController->SetAbsoluteTolerance(DRIVE_DIST_TOLERANCE);
	rightDistanceController->SetAbsoluteTolerance(DRIVE_DIST_TOLERANCE);
	leftDistanceController->Disable();
	rightDistanceController->Disable();




//////////////////
	rotationMeasure = new DrivetrainRotationMeasure(leftDistanceEncoder, rightDistanceEncoder);
	turnOutput = new DriveTurnController();

	turnController = new PIDController(.002, 0.000001, 0, rotationMeasure, turnOutput);
	turnController->SetAbsoluteTolerance(DRIVE_TURN_TOLERANCE);
	turnController->SetSetpoint(0);
	turnController->SetOutputRange(-MAX_SPEED_EV, MAX_SPEED_EV);
	//turnController->Disable();
}

void DrivetrainSub::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystickCmd());
	//Please Comment out once this command exists.
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand())
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DrivetrainSub::Drive(float leftSpeed, float rightSpeed) {
	rightMotor->Set(rightSpeed);
	leftMotor->Set(leftSpeed);
}

void DrivetrainSub::PIDDrive(float speed) {
	// In order to avoid having the robot spasm when it overshoots the desired speed, set the
	// output range to prevent the motor from turning in the opposite direction.
	if(speed > 0)
	{
		leftCurSpeedController->SetOutputRange(0.0, 1.0);
		rightCurSpeedController->SetOutputRange(0.0, 1.0);
	}
	else if(speed < 0)
	{
		leftCurSpeedController->SetOutputRange(-1.0, 0.0);
		rightCurSpeedController->SetOutputRange(-1.0, 0.0);
	}
	leftCurSpeedController->SetSetpoint(speed);
	rightCurSpeedController->SetSetpoint(speed);
}

void DrivetrainSub::PIDDrive(float leftSpeed, float rightSpeed) {
	leftCurSpeedController->SetSetpoint(MAX_SPEED_EV*leftSpeed);
	rightCurSpeedController->SetSetpoint(MAX_SPEED_EV*rightSpeed);
}

void DrivetrainSub::PIDDist(float distance, float speed) {
	leftDistanceController->SetSetpoint(distance);
	rightDistanceController->SetSetpoint(distance);
	leftDistanceController->SetOutputRange(-fabs(speed / MAX_SPEED_EV), fabs(speed / MAX_SPEED_EV));
	rightDistanceController->SetOutputRange(-fabs(speed / MAX_SPEED_EV), fabs(speed / MAX_SPEED_EV));
}

void DrivetrainSub::SetExternallyAccessiblePid( int id ) {
	pidGetSetId = id;
}

void DrivetrainSub::SetP(float p){
	switch(pidGetSetId) {
	case NORMAL_SPEED_CTRL_ID:
		leftDriveSpeedController->SetPID(p, leftDriveSpeedController->GetI(), leftDriveSpeedController->GetD());
		rightDriveSpeedController->SetPID(p, rightDriveSpeedController->GetI(), rightDriveSpeedController->GetD());
		break;
	case AUTO_SPEED_CTRL_ID:
		leftAutoSpeedController->SetPID(p, leftAutoSpeedController->GetI(), leftAutoSpeedController->GetD());
		rightAutoSpeedController->SetPID(p, rightAutoSpeedController->GetI(), rightAutoSpeedController->GetD());
		break;
	case DISTANCE_CTRL_ID:
		leftDistanceController->SetPID(p, leftDistanceController->GetI(), leftDistanceController->GetD());
		rightDistanceController->SetPID(p, rightDistanceController->GetI(), rightDistanceController->GetD());
		break;
	case TURN_CTRL_ID:
		turnController->SetPID(p,turnController->GetI(),turnController->GetD());
		break;
	}
}

float DrivetrainSub::GetP(){
	float val = 0.0;

	switch(pidGetSetId) {
	case NORMAL_SPEED_CTRL_ID:
		val = leftDriveSpeedController->GetP();
		break;
	case AUTO_SPEED_CTRL_ID:
		val = leftAutoSpeedController->GetP();
		break;
	case DISTANCE_CTRL_ID:
		val = leftDistanceController->GetP();
		break;
	case TURN_CTRL_ID:
		val = turnController->GetP();
		break;
	}
	return val;
}

void DrivetrainSub::SetI(float i){
	switch(pidGetSetId) {
	case NORMAL_SPEED_CTRL_ID:
		leftDriveSpeedController->SetPID(leftDriveSpeedController->GetP(), i, leftDriveSpeedController->GetD());
		rightDriveSpeedController->SetPID(rightDriveSpeedController->GetP(), i, rightDriveSpeedController->GetD());
		break;
	case AUTO_SPEED_CTRL_ID:
		leftAutoSpeedController->SetPID(leftAutoSpeedController->GetP(), i, leftAutoSpeedController->GetD());
		rightAutoSpeedController->SetPID(rightAutoSpeedController->GetP(), i, rightAutoSpeedController->GetD());
		break;
	case DISTANCE_CTRL_ID:
		leftDistanceController->SetPID(leftDistanceController->GetP(), i, leftDistanceController->GetD());
		rightDistanceController->SetPID(rightDistanceController->GetP(), i, rightDistanceController->GetD());
		break;
	case TURN_CTRL_ID:
		turnController->SetPID(turnController->GetP(), i, turnController->GetD());
		break;
	}
}

float DrivetrainSub::GetI(){
	float val = 0.0;

	switch(pidGetSetId) {
	case NORMAL_SPEED_CTRL_ID:
		val = leftDriveSpeedController->GetI();
		break;
	case AUTO_SPEED_CTRL_ID:
		val = leftAutoSpeedController->GetI();
		break;
	case DISTANCE_CTRL_ID:
		val = leftDistanceController->GetI();
		break;
	case TURN_CTRL_ID:
		val = turnController->GetI();
		break;
	}
	return val;
}

void DrivetrainSub::SetD(float d){
	switch(pidGetSetId) {
	case NORMAL_SPEED_CTRL_ID:
		leftDriveSpeedController->SetPID(leftDriveSpeedController->GetP(), leftDriveSpeedController->GetI(), d);
		rightDriveSpeedController->SetPID(rightDriveSpeedController->GetP(), rightDriveSpeedController->GetI(), d);
		break;
	case AUTO_SPEED_CTRL_ID:
		leftAutoSpeedController->SetPID(leftAutoSpeedController->GetP(), leftAutoSpeedController->GetI(), d);
		rightAutoSpeedController->SetPID(rightAutoSpeedController->GetP(), rightAutoSpeedController->GetI(), d);
		break;
	case DISTANCE_CTRL_ID:
		leftDistanceController->SetPID(leftDistanceController->GetP(), leftDistanceController->GetI(), d);
		rightDistanceController->SetPID(rightDistanceController->GetP(), rightDistanceController->GetI(), d);
		break;
	case TURN_CTRL_ID:
		turnController->SetPID(turnController->GetP(), turnController->GetI(), d);
		break;
	}
}

float DrivetrainSub::GetD(){
	float val = 0.0;

	switch(pidGetSetId) {
	case NORMAL_SPEED_CTRL_ID:
		val = leftDriveSpeedController->GetD();
		break;
	case AUTO_SPEED_CTRL_ID:
		val = leftAutoSpeedController->GetD();
		break;
	case DISTANCE_CTRL_ID:
		val = leftDistanceController->GetD();
		break;
	case TURN_CTRL_ID:
		val = turnController->GetD();
		break;
	}
	return val;
}

int DrivetrainSub::GetRawLeftEnc(){
	return (int) leftDistanceEncoder->GetRaw();
}
int DrivetrainSub::GetLeftEnc(){
	return (int) leftDistanceEncoder->GetDistance();
}
int DrivetrainSub::GetRawRightEnc(){
	return (int) rightDistanceEncoder->GetRaw();
}
int DrivetrainSub::GetRightEnc(){
	return (int) rightDistanceEncoder->GetDistance();
}
void DrivetrainSub::ResetDrive(){
	// This also resets the virtual speed encoders
	leftDistanceEncoder->Reset();
	rightDistanceEncoder->Reset();
}
void DrivetrainSub::ToggleControls(){
	if(controlState == FPS_DRIVE_CONTROLS){
		controlState = TANK_DRIVE_CONTROLS;
	}
	else{
		controlState = FPS_DRIVE_CONTROLS;
	}
}
int DrivetrainSub::GetControls()
{
	return controlState;
}
void DrivetrainSub::EnableDistancePID(){
	leftDistanceController->Enable();
	rightDistanceController->Enable();
	turnController->SetSetpoint(0);
}

void DrivetrainSub::SetSpeedPIDMode(int mode) {
	// Disable the current PID controller and "connect" the new PID controller
	switch(mode) {
	case SPEED_MODE_AUTO:
		leftCurSpeedController->Disable();
		rightCurSpeedController->Disable();
		leftCurSpeedController = leftAutoSpeedController;
		rightCurSpeedController = rightAutoSpeedController;
		break;

	case SPEED_MODE_NORMAL:
	default:
		leftCurSpeedController->Disable();
		rightCurSpeedController->Disable();
		leftCurSpeedController = leftDriveSpeedController;
		rightCurSpeedController = rightDriveSpeedController;
		break;
	}
}

void DrivetrainSub::EnableSpeedPID(){
	leftCurSpeedController->Enable();
	rightCurSpeedController->Enable();
}

void DrivetrainSub::DisableSpeedPID(){
	leftCurSpeedController->Disable();
	rightCurSpeedController->Disable();
}

void DrivetrainSub::DisableTurnPID(){
	turnController->Disable();
}

void DrivetrainSub::EnableTurnPID(){
	turnController->SetSetpoint(0);
	turnController->Enable();
}

void DrivetrainSub::DisableDistancePID(){
	leftDistanceController->Disable();
	rightDistanceController->Disable();
}

void DrivetrainSub::SetLeftSetpoint(int setpoint, float speed){
	// Negatives here are to fix a strange bug where different output ranges resulted in different speeds on either side
	leftDistanceController->SetOutputRange(-fabs(speed / MAX_SPEED_EV), fabs(speed / MAX_SPEED_EV));
	//leftController->SetSetpoint(-setpoint);
	leftDistanceController->SetSetpoint(setpoint);
}

void DrivetrainSub::SetRightSetpoint(int setpoint, float speed){
	rightDistanceController->SetOutputRange(-fabs(speed / MAX_SPEED_EV), fabs(speed / MAX_SPEED_EV));
	rightDistanceController->SetSetpoint(setpoint);
}

bool DrivetrainSub::isOnDistTarget() {
	return leftDistanceController->OnTarget() && rightDistanceController->OnTarget();
}

bool DrivetrainSub::isLeftOnTarget(){
	return leftDistanceController->OnTarget();
}

bool DrivetrainSub::isRightOnTarget(){
	return rightDistanceController->OnTarget();
}

double DrivetrainSub::GetLeftEncoderRate(){
	return leftDistanceEncoder->GetRate();
}

double DrivetrainSub::GetRightEncoderRate(){
	return rightDistanceEncoder->GetRate();
}

void DrivetrainSub::SetTurnModifier(float turnModifier){

	SmartDashboard::PutNumber("Drivetrain TurnModifier", turnModifier);
	SmartDashboard::PutNumber("Drivetrain rotation", rotationMeasure->PIDGet());
//	leftTurnModifier = -turnModifier;												// TODO:  Fix or remove
//	rightTurnModifier = turnModifier;
}
