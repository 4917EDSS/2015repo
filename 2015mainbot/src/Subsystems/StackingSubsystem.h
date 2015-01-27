#ifndef StackingSubsystem_H
#define StackingSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class StackingSubsystem: public Subsystem
{
private:
	DigitalInput* armStopLimit;
	DoubleSolenoid* flapActuator;
	bool isFlapOpen;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	StackingSubsystem(int flap_channelopen, int flap_channelclosed, int armStopLimit_channel);
	void InitDefaultCommand();
	bool isPressed();
	void setOpen();
	void setClosed();
	bool getFlapOpen();
};

#endif
