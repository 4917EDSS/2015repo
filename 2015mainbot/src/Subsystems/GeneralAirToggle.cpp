#include "GeneralAirToggle.h"
#include "../RobotMap.h"

GeneralAirToggle::GeneralAirToggle(int channel_1, int channel_2) : Subsystem("GeneralAirToggle")
{
	articulationRight = new Solenoid(channel_1);
	articulationLeft = new Solenoid(channel_2);
}

void GeneralAirToggle::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void GeneralAirToggle::toggle(){
	bool toggleState = !(articulationRight->Get());
	articulationRight->Set(toggleState);
	articulationLeft->Set(!toggleState);
}

void GeneralAirToggle::set(bool setTo){
	articulationRight->Set(setTo);
	articulationLeft->Set(!setTo);
}

bool GeneralAirToggle::get(){
	return articulationRight->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
