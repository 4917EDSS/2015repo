#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "RobotParameters.h"

DrivetrainSub::DrivetrainSub(int rightMotorC, int leftMotorC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C) :
		Subsystem("DrivetrainSub")
{
	rightMotor = new Talon(rightMotorC);
	leftMotor = new Talon(leftMotorC);
	leftEncoderSpeed = new Encoder4917(leftEncoder1C, leftEncoder2C);
	rightEncoderSpeed = new Encoder4917(rightEncoder1C, rightEncoder2C);
	leftEncoder  = leftEncoderSpeed->GetEncoder();
	rightEncoder = rightEncoderSpeed->GetEncoder();

	controlState = FPS_DRIVE_CONTROLS;

	leftDoubleController = new DoublePIDController(leftEncoderSpeed, leftMotor);
	rightDoubleController = new DoublePIDController(rightEncoderSpeed, rightMotor);
	rightDoubleController->SetAbsoluteTolerance(5);
	rightDoubleController->SetOutputRange(-1,1);
	leftDoubleController->SetAbsoluteTolerance(5);
	leftDoubleController->SetOutputRange(-1,1);

	leftController = new PIDController(0.00000001,0.5,0, leftEncoder, leftDoubleController);
	rightController = new PIDController(0.00000001,0.5,0, rightEncoder, rightDoubleController);
	rightController->SetAbsoluteTolerance(DRIVE_DIST_TOLERANCE);
	leftController->SetAbsoluteTolerance(DRIVE_DIST_TOLERANCE);
	lastSpeed = 0;

	rightEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE*ENCODER_CONVERSION_FACTOR);
	leftEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE*ENCODER_CONVERSION_FACTOR);
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
	leftDoubleController->PIDWrite(1000*leftSpeed);
	rightDoubleController->PIDWrite(1000*rightSpeed);
}

void DrivetrainSub::SetP(float p){
	leftDoubleController->GetPIDController()->SetPID(p,leftDoubleController->GetPIDController()->GetI(),leftDoubleController->GetPIDController()->GetD());
	rightDoubleController->GetPIDController()->SetPID(p,rightDoubleController->GetPIDController()->GetI(),rightDoubleController->GetPIDController()->GetD());
}
float DrivetrainSub::GetP(){
	return leftDoubleController->GetPIDController()->GetP();
}
void DrivetrainSub::SetI(float i){
	leftDoubleController->GetPIDController()->SetPID(leftDoubleController->GetPIDController()->GetP(),i,leftDoubleController->GetPIDController()->GetD());
	rightDoubleController->GetPIDController()->SetPID(rightDoubleController->GetPIDController()->GetP(),i,rightDoubleController->GetPIDController()->GetD());
}
float DrivetrainSub::GetI(){
	return leftDoubleController->GetPIDController()->GetI();
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
void DrivetrainSub::EnablePID(){
	leftController->Enable();
	rightController->Enable();
	leftDoubleController->Enable();
	rightDoubleController->Enable();
}
void DrivetrainSub::DisablePID(){
	leftController->Disable();
	rightController->Disable();
	leftDoubleController->Disable();
	rightDoubleController->Disable();
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
