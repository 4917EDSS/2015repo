#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "RobotParameters.h"

DrivetrainSub::DrivetrainSub(int rightMotorC, int leftMotorC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C) :
		Subsystem("DrivetrainSub")
{
	leftTurnModifier = 0;
	rightTurnModifier = 0;

	rightMotor = new Talon(rightMotorC);
	leftMotor = new Talon(leftMotorC);
	leftEncoderSpeed = new Encoder4917(leftEncoder1C, leftEncoder2C);
	rightEncoderSpeed = new Encoder4917(rightEncoder1C, rightEncoder2C);
	leftEncoder  = leftEncoderSpeed->GetEncoder();
	rightEncoder = rightEncoderSpeed->GetEncoder();

	controlState = FPS_DRIVE_CONTROLS;

	leftDoubleController = new DoublePIDController(leftEncoderSpeed, leftMotor, &leftTurnModifier);
	rightDoubleController = new DoublePIDController(rightEncoderSpeed, rightMotor, &rightTurnModifier);
	rightDoubleController->SetAbsoluteTolerance(5);
	rightDoubleController->SetOutputRange(-1,1);
	leftDoubleController->SetAbsoluteTolerance(5);
	leftDoubleController->SetOutputRange(-1,1);

	leftController = new PIDController(SPEED_P_VALUE,SPEED_I_VALUE,SPEED_D_VALUE, leftEncoder, leftDoubleController);
	rightController = new PIDController(SPEED_P_VALUE,SPEED_I_VALUE,SPEED_D_VALUE, rightEncoder, rightDoubleController);
	rightController->SetAbsoluteTolerance(DRIVE_DIST_TOLERANCE);
	leftController->SetAbsoluteTolerance(DRIVE_DIST_TOLERANCE);
	lastSpeed = 0;

	rightEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE*ENCODER_CONVERSION_FACTOR);
	leftEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE*ENCODER_CONVERSION_FACTOR);
	rightController->Disable();
	rightDoubleController->Disable();
	leftController->Disable();
	leftDoubleController->Disable();

	rotationMeasure = new DrivetrainRotationMeasure(leftEncoder, rightEncoder);
	turnOutput = new DriveTurnController();


	//Had a D value of 0.0001 here. I value of 0, and P value of 3.
	turnController = new PIDController(0.0001,3,0, rotationMeasure, turnOutput);
	turnController->SetAbsoluteTolerance(DRIVE_TURN_TOLERANCE);
	turnController->SetSetpoint(0);
	turnController->SetOutputRange(-MAX_SPEED_EV, MAX_SPEED_EV);
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

void DrivetrainSub::PIDDrive(float leftSpeed, float rightSpeed) {

	leftDoubleController->PIDWrite(MAX_SPEED_EV*leftSpeed);
	rightDoubleController->PIDWrite(MAX_SPEED_EV*rightSpeed);
}

void DrivetrainSub::SetP(float p){

	turnController->SetPID(p,turnController->GetI(),turnController->GetD());

//	leftController->SetPID(p,leftController->GetI(),leftController->GetD());
//	rightController->SetPID(p,rightController->GetI(),rightController->GetD());
}
float DrivetrainSub::GetP(){
	return turnController->GetP();
}
void DrivetrainSub::SetI(float i){
	turnController->SetPID(turnController->GetP(),i,turnController->GetD());

//	leftController->SetPID(leftController->GetP(),i,leftController->GetD());
//	rightController->SetPID(rightController->GetP(),i,rightController->GetD());
}
float DrivetrainSub::GetI(){
	return turnController->GetI();
}

int DrivetrainSub::GetRawLeftEnc(){
	return (int) leftEncoder->GetRaw();
}
int DrivetrainSub::GetLeftEnc(){
	return (int) leftEncoder->GetDistance();
}
int DrivetrainSub::GetRawRightEnc(){
	return (int) rightEncoder->GetRaw();
}
int DrivetrainSub::GetRightEnc(){
	return (int) rightEncoder->GetDistance();
}
void DrivetrainSub::ResetDrive(){

	leftEncoder->Reset();
	rightEncoder->Reset();
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
	leftController->Enable();
	rightController->Enable();
	leftDoubleController->Enable();
	rightDoubleController->Enable();
	turnController->Enable();
	turnController->SetSetpoint(0);
	leftTurnModifier = 0;
	rightTurnModifier = 0;

}
void DrivetrainSub::EnableSpeedPID(){
	leftDoubleController->Enable();
	rightDoubleController->Enable();
}
void DrivetrainSub::DisableSpeedPID(){
	leftDoubleController->Disable();
	rightDoubleController->Disable();
}
void DrivetrainSub::DisableDistancePID(){
	//leftDoubleController->GetPIDController()->SetPID(leftDoubleController->GetPIDController()->GetP(),leftDoubleController->GetPIDController()->GetI()/2.0,leftDoubleController->GetPIDController()->GetD());
	//rightDoubleController->GetPIDController()->SetPID(rightDoubleController->GetPIDController()->GetP(),rightDoubleController->GetPIDController()->GetI()/2.0,rightDoubleController->GetPIDController()->GetD());
	leftController->Disable();
	rightController->Disable();
	leftDoubleController->Disable();
	rightDoubleController->Disable();
	turnController->Disable();
	leftTurnModifier = 0;
	rightTurnModifier = 0;
}
void DrivetrainSub::SetLeftSetpoint(int setpoint, float speed){
	// Negatives here are to fix a strange bug where different output ranges resulted in different speeds on either side
	leftController->SetOutputRange(-fabs(speed), fabs(speed));
	//leftController->SetSetpoint(-setpoint);
	leftController->SetSetpoint(setpoint);
}
void DrivetrainSub::SetRightSetpoint(int setpoint, float speed){
	rightController->SetOutputRange(-fabs(speed), fabs(speed));
	rightController->SetSetpoint(setpoint);
}
bool DrivetrainSub::isLeftOnTarget(){
	return leftController->OnTarget();
}
bool DrivetrainSub::isRightOnTarget(){
	return rightController->OnTarget();
}
double DrivetrainSub::GetLeftEncoderRate(){
	return leftEncoder->GetRate();
}
double DrivetrainSub::GetRightEncoderRate(){
	return rightEncoder->GetRate();
}
void DrivetrainSub::SetTurnModifier(float turnModifier){

	SmartDashboard::PutNumber("Drivetrain TurnModifier", turnModifier);
	SmartDashboard::PutNumber("Drivetrain rotation", rotationMeasure->PIDGet());
	leftTurnModifier = -turnModifier;
	rightTurnModifier = turnModifier;
}
