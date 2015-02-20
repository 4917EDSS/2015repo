#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "RobotParameters.h"

DrivetrainSub::DrivetrainSub(int rightMotorC, int leftMotorC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C) :
		Subsystem("DrivetrainSub")
{
	rightMotor = new Talon(rightMotorC);
	leftMotor = new Talon(leftMotorC);
	leftEncoder = new Encoder(leftEncoder1C, leftEncoder2C);
	rightEncoder = new Encoder(rightEncoder1C, rightEncoder2C);

	controlState = FPS_DRIVE_CONTROLS;

	leftController = new PIDController(0.01,0,0, leftEncoder, leftMotor);
	rightController = new PIDController(0.01,0,0, rightEncoder, rightMotor);
	rightController->SetAbsoluteTolerance(DRIVE_DIST_TOLERANCE);
	rightController->SetOutputRange(-1,1);
	leftController->SetAbsoluteTolerance(DRIVE_DIST_TOLERANCE);
	leftController->SetOutputRange(1,-1);
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
	//because opposite motors are facing outwards, need the negative
	if(leftSpeed > 1.0){
		leftSpeed = 1.0;
	}
	else if(leftSpeed < -1.0){
		leftSpeed = -1.0;
	}
	if(rightSpeed > 1.0){
		rightSpeed = 1.0;
	}
	else if(rightSpeed < -1.0){
		rightSpeed = -1.0;
	}

	rightMotor->Set(rightSpeed);
	leftMotor->Set(-leftSpeed);

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
}
void DrivetrainSub::DisablePID(){
	leftController->Disable();
	rightController->Disable();
}
void DrivetrainSub::SetLeftSetpoint(int setpoint, float speed){
	leftController->SetOutputRange(speed, -speed);
	leftController->SetSetpoint(setpoint);
}
void DrivetrainSub::SetRightSetpoint(int setpoint, float speed){
	rightController->SetOutputRange(-speed, speed);
	rightController->SetSetpoint(setpoint);
}
bool DrivetrainSub::isLeftOnTarget(){
	return leftController->OnTarget();
}
bool DrivetrainSub::isRightOnTarget(){
	return rightController->OnTarget();
}
