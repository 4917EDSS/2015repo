#include "drivetrain.h"
#include "../Robotmap.h"
#include "../Commands/DriveWithJoystickCommand.h"

Drivetrain::Drivetrain(int frontright_channel, int backright_channel, int frontleft_channel, int backleft_channel) : Subsystem("drivetrain") {
	frontright = new Talon(frontright_channel);
	backright = new Talon(backright_channel);
	backleft = new Talon(backleft_channel);
	frontleft = new Talon(frontleft_channel);
	
	
}
void Drivetrain::InitDefaultCommand(){
	SetDefaultCommand(new DriveWithJoystickCommand());
}
    
void Drivetrain::drive(float LeftSpeed, float RightSpeed) {
	frontright->Set(RightSpeed);
	backright->Set(RightSpeed);
	frontleft->Set(LeftSpeed);
	backleft->Set(LeftSpeed);
	
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
