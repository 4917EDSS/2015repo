#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "RobotParameters.h"

DrivetrainSub::DrivetrainSub(int rightMotorC, int leftMotorC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C) :
		Subsystem("DrivetrainSub")
{
	rightMotor = new Talon(rightMotorC);
	leftMotor = new Talon(leftMotorC);
	leftSpeedVirtualEncoder = new Encoder4917(leftEncoder1C, leftEncoder2C);
	rightSpeedVirtualEncoder = new Encoder4917(rightEncoder1C, rightEncoder2C);
	leftDistanceEncoder  = leftSpeedVirtualEncoder->GetEncoder();
	rightDistanceEncoder = rightSpeedVirtualEncoder->GetEncoder();

	controlState = FPS_DRIVE_CONTROLS;
	pidGetSetId = SPEED_CTRL_ID;

	// Set encoder parameters
	leftDistanceEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE*ENCODER_CONVERSION_FACTOR);
	rightDistanceEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE*ENCODER_CONVERSION_FACTOR);

	// Set PID controller parameters
	// Speed is calculated from the distance encoders
	leftSpeedController = new PIDController(SPEED_P_VALUE, SPEED_I_VALUE, SPEED_D_VALUE, SPEED_F_VALUE, leftSpeedVirtualEncoder, leftMotor);
	rightSpeedController = new PIDController(SPEED_P_VALUE, SPEED_I_VALUE, SPEED_D_VALUE, SPEED_F_VALUE, rightSpeedVirtualEncoder, rightMotor);
	leftSpeedController->SetAbsoluteTolerance(DRIVE_SPEED_TOLERANCE);
	rightSpeedController->SetAbsoluteTolerance(DRIVE_SPEED_TOLERANCE);
	leftSpeedController->Disable();
	rightSpeedController->Disable();




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
	leftSpeedController->SetSetpoint(speed);
	rightSpeedController->SetSetpoint(speed);
}

void DrivetrainSub::PIDDrive(float leftSpeed, float rightSpeed) {

	//leftDoubleController->PIDWrite(MAX_SPEED_EV*leftSpeed);		////////////////////////////// TODO: Fix
	//rightDoubleController->PIDWrite(MAX_SPEED_EV*rightSpeed);
}



void DrivetrainSub::SetExternallyAccessiblePid( int id ) {
	pidGetSetId = id;
}

void DrivetrainSub::SetP(float p){
	switch(pidGetSetId) {
	case SPEED_CTRL_ID:
		leftSpeedController->SetPID(p, leftSpeedController->GetI(), leftSpeedController->GetD());
		rightSpeedController->SetPID(p, rightSpeedController->GetI(), rightSpeedController->GetD());
		break;
	case DRIVE_CTRL_ID:
		// TODO: Add
		break;
	case TURN_CTRL_ID:
		turnController->SetPID(p,turnController->GetI(),turnController->GetD());
		break;
	}
}

float DrivetrainSub::GetP(){
	float val = 0.0;

	switch(pidGetSetId) {
	case SPEED_CTRL_ID:
		val = leftSpeedController->GetP();
		break;
	case DRIVE_CTRL_ID:
		// TODO: Add
		break;
	case TURN_CTRL_ID:
		val = turnController->GetP();
		break;
	}
	return val;
}

void DrivetrainSub::SetI(float i){
	switch(pidGetSetId) {
	case SPEED_CTRL_ID:
		leftSpeedController->SetPID(leftSpeedController->GetP(), i, leftSpeedController->GetD());
		rightSpeedController->SetPID(rightSpeedController->GetP(), i, rightSpeedController->GetD());
		break;
	case DRIVE_CTRL_ID:
		// TODO: Add
		break;
	case TURN_CTRL_ID:
		turnController->SetPID(turnController->GetP(), i, turnController->GetD());
		break;
	}
}

float DrivetrainSub::GetI(){
	float val = 0.0;

	switch(pidGetSetId) {
	case SPEED_CTRL_ID:
		val = leftSpeedController->GetI();
		break;
	case DRIVE_CTRL_ID:
		// TODO: Add
		break;
	case TURN_CTRL_ID:
		val = turnController->GetI();
		break;
	}
	return val;
}

void DrivetrainSub::SetD(float d){
	switch(pidGetSetId) {
	case SPEED_CTRL_ID:
		leftSpeedController->SetPID(leftSpeedController->GetP(), leftSpeedController->GetI(), d);
		rightSpeedController->SetPID(rightSpeedController->GetP(), rightSpeedController->GetI(), d);
		break;
	case DRIVE_CTRL_ID:
		// TODO: Add
		break;
	case TURN_CTRL_ID:
		turnController->SetPID(turnController->GetP(), turnController->GetI(), d);
		break;
	}
}

float DrivetrainSub::GetD(){
	float val = 0.0;

	switch(pidGetSetId) {
	case SPEED_CTRL_ID:
		val = leftSpeedController->GetD();
		break;
	case DRIVE_CTRL_ID:
		// TODO: Add
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
	//leftDoubleController->GetPIDController()->SetPID(leftDoubleController->GetPIDController()->GetP(),leftDoubleController->GetPIDController()->GetI()*2,leftDoubleController->GetPIDController()->GetD());
	//rightDoubleController->GetPIDController()->SetPID(rightDoubleController->GetPIDController()->GetP(),rightDoubleController->GetPIDController()->GetI()*2,rightDoubleController->GetPIDController()->GetD());
//	leftSpeedController->Enable();
//	rightSpeedController->Enable();
//	leftDoubleController->Enable();
//	rightDoubleController->Enable();
	turnController->SetSetpoint(0);
//	leftTurnModifier = 0;
//	rightTurnModifier = 0;
}

void DrivetrainSub::SetSpeedPIDMode(int mode) {
	switch(mode) {
	case SPEED_MODE_SOFT_START:
		leftSpeedController->SetPID(SOFT_START_SPEED_P_VALUE, SOFT_START_SPEED_I_VALUE, SOFT_START_SPEED_D_VALUE, SOFT_START_SPEED_F_VALUE);
		rightSpeedController->SetPID(SOFT_START_SPEED_P_VALUE, SOFT_START_SPEED_I_VALUE, SOFT_START_SPEED_D_VALUE, SOFT_START_SPEED_F_VALUE);
		break;

	case SPEED_MODE_NORMAL:
	default:
		leftSpeedController->SetPID(SPEED_P_VALUE, SPEED_I_VALUE, SPEED_D_VALUE, SPEED_F_VALUE);
		rightSpeedController->SetPID(SPEED_P_VALUE, SPEED_I_VALUE, SPEED_D_VALUE, SPEED_F_VALUE);
		break;
	}
}

void DrivetrainSub::EnableSpeedPID(){
	leftSpeedController->Enable();
	rightSpeedController->Enable();
}

void DrivetrainSub::DisableSpeedPID(){
	leftSpeedController->Disable();
	rightSpeedController->Disable();
}

void DrivetrainSub::DisableTurnPID(){
	turnController->Disable();
}

void DrivetrainSub::EnableTurnPID(){
	turnController->SetSetpoint(0);
	turnController->Enable();
}

void DrivetrainSub::DisableDistancePID(){
	//leftDoubleController->GetPIDController()->SetPID(leftDoubleController->GetPIDController()->GetP(),leftDoubleController->GetPIDController()->GetI()/2.0,leftDoubleController->GetPIDController()->GetD());
	//rightDoubleController->GetPIDController()->SetPID(rightDoubleController->GetPIDController()->GetP(),rightDoubleController->GetPIDController()->GetI()/2.0,rightDoubleController->GetPIDController()->GetD());
//	leftSpeedController->Disable();
//	rightSpeedController->Disable();
//	leftDoubleController->Disable();
//	rightDoubleController->Disable();
//	leftTurnModifier = 0;
//	rightTurnModifier = 0;
}

void DrivetrainSub::SetLeftSetpoint(int setpoint, float speed){
	// Negatives here are to fix a strange bug where different output ranges resulted in different speeds on either side
	leftSpeedController->SetOutputRange(-fabs(speed / MAX_SPEED_EV), fabs(speed / MAX_SPEED_EV));
	//leftController->SetSetpoint(-setpoint);
	leftSpeedController->SetSetpoint(setpoint);
}

void DrivetrainSub::SetRightSetpoint(int setpoint, float speed){
	rightSpeedController->SetOutputRange(-fabs(speed / MAX_SPEED_EV), fabs(speed / MAX_SPEED_EV));
	rightSpeedController->SetSetpoint(setpoint);
}

bool DrivetrainSub::isLeftOnTarget(){
	return leftSpeedController->OnTarget();
}

bool DrivetrainSub::isRightOnTarget(){
	return rightSpeedController->OnTarget();
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
//	leftTurnModifier = -turnModifier;
//	rightTurnModifier = turnModifier;
}
