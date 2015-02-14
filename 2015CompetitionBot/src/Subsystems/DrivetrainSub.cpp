#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "RobotParameters.h"

DrivetrainSub::DrivetrainSub(int frontrightC, int backrightC, int frontleftC, int backleftC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C) :
		Subsystem("DrivetrainSub")
{
	frontRight = new Talon(frontrightC);
	backRight = new Talon(backrightC);
	frontLeft = new Talon(frontleftC);
	backLeft = new Talon(backleftC);
	leftEncoder = new Encoder(leftEncoder1C, leftEncoder2C);
	rightEncoder = new Encoder(rightEncoder1C, rightEncoder2C);
	controlState = TANK_DRIVE_CONTROLS;
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

	frontRight->Set(rightSpeed);
	backRight->Set(rightSpeed);
	frontLeft->Set(-leftSpeed);
	backLeft->Set(-leftSpeed);
}
int DrivetrainSub::GetRawLeftEnc(){
	return (int) leftEncoder->GetRaw();
}
int DrivetrainSub::GetLeftEnc(){
	leftEncoder->SetDistancePerPulse(2.75);
	return (int) leftEncoder->GetDistance();
}
int DrivetrainSub::GetRawRightEnc(){
	return (int) rightEncoder->GetRaw();
}
int DrivetrainSub::GetRightEnc(){
	rightEncoder->SetDistancePerPulse(2.75);
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
