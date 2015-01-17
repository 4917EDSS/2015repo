#ifndef GeneralAirToggle_H
#define GeneralAirToggle_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

// A general class for toggling between two sides of a pneumatic actuator
class GeneralAirToggle: public Subsystem
{
private:
	Solenoid* articulationRight;
	Solenoid* articulationLeft;
	bool toggleState;
public:
	GeneralAirToggle(int channel_1, int channel_2);
	void toggle();
	bool get();
	void set(bool setTo);
	void InitDefaultCommand();
};

#endif
