#include "LiftSubsystem.h"
#include "../Robotmap.h"

LiftSubsystem::LiftSubsystem(int lift_channel) : Subsystem("LiftSubsystem") {
	lifterMotor = new Talon(lift_channel);
}
    
void LiftSubsystem::InitDefaultCommand() {
	
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void LiftSubsystem::setMotor(float motorSpeed){
	lifterMotor->Set(motorSpeed);
}
