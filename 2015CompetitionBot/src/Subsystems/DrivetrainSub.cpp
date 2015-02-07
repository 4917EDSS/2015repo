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

void DrivetrainSub::drive(float leftSpeed, float rightSpeed) {
	//because opposite motors are facing outwards, need the negative
	if (fabs(leftSpeed - rightSpeed) < DRIVE_DIFFERENCE_TOLERANCE) {
		leftSpeed = fmax(leftSpeed, rightSpeed);
		rightSpeed = leftSpeed;
	}
	frontRight->Set(rightSpeed);
	backRight->Set(rightSpeed);
	frontLeft->Set(-leftSpeed);
	backLeft->Set(-leftSpeed);
}
int DrivetrainSub::GetLeftEnc(){

	return (int) leftEncoder->GetRaw();
}

int DrivetrainSub::GetRightEnc(){

	return (int) rightEncoder->GetRaw();
}
void DrivetrainSub::ResetDrive(){

	leftEncoder->Reset();
	rightEncoder->Reset();
}
