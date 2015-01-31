#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"

DrivetrainSub::DrivetrainSub(int frontrightC, int backrightC, int frontleftC, int backleftC) :
		Subsystem("DrivetrainSub")
{
	frontRight = new Talon(frontrightC);
	backRight = new Talon(backrightC);
	frontLeft = new Talon(frontleftC);
	backLeft = new Talon(backleftC);

}

void DrivetrainSub::InitDefaultCommand()
{
	//SetDefaultCommand(new DriveWithJoystickCmd()); Please Comment out once this command exists.
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DrivetrainSub::drive(float leftSpeed, float rightSpeed) {
	frontRight->Set(rightSpeed);
	backRight->Set(rightSpeed);
	frontLeft->Set(leftSpeed);
	backLeft->Set(leftSpeed);
}


