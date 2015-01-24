#ifndef StackingSubsystem_H
#define StackingSubsystem_H

#include "Commands/Subsystem.h"
#include "Subsystems/GeneralAirToggle.h"
#include "WPILib.h"

class StackingSubsystem: public Subsystem
{
private:
	GeneralAirToggle* secondaryArms;
	DigitalInput* armStopLimit;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	StackingSubsystem(int secondaryarm_channel1, int secondaryarm_channel2, int armStopLimit_channel);
	void InitDefaultCommand();
	bool isPressed();
	void setOpen();
	void setClosed();
};

#endif
