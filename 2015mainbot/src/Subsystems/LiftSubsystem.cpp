#include "LiftSubsystem.h"
#include "../Robotmap.h"

LiftSubsystem::LiftSubsystem(int lift_channel1, int lift_channel2) : Subsystem("LiftSubsystem") {
	lifterArticulationRight = new Solenoid(lift_channel1);
	lifterArticulationLeft = new Solenoid(lift_channel2);
	isUp = false;
}
    
void LiftSubsystem::InitDefaultCommand() {
	
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void LiftSubsystem::toggleUpDown(){
	isUp = !isUp;
	lifterArticulationRight->Set(isUp);
	lifterArticulationLeft->Set(!isUp);
}
