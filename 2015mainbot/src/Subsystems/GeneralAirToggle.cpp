#include "GeneralAirToggle.h"
#include "../RobotMap.h"

GeneralAirToggle::GeneralAirToggle(int channel_1, int channel_2) : Subsystem("GeneralAirToggle")
{
	toggleState = false;
	articulationRight = new Solenoid(channel_1);
	articulationLeft = new Solenoid(channel_2);
}

void GeneralAirToggle::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void GeneralAirToggle::toggle(){
	toggleState = !toggleState;
	if (toggleState){
		articulationRight->Set(toggleState);
		articulationLeft->Set(!toggleState);
	}
	else {
		articulationRight->Set(!toggleState);
		articulationLeft->Set(toggleState);
	}
}

void GeneralAirToggle::set(bool setTo){
	articulationRight->Set(setTo);
	articulationLeft->Set(!setTo);
}

bool GeneralAirToggle::get(){
	return articulationRight;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
