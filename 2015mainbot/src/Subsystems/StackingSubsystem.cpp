#include "StackingSubsystem.h"
#include "../RobotMap.h"
#include "WPILib.h"

StackingSubsystem::StackingSubsystem(int flap_channelopen, int flap_channelclosed, int armStopLimit_channel):
		Subsystem("StackingSubsystem")
{
	flapActuator = new DoubleSolenoid(flap_channelopen, flap_channelclosed);
	armStopLimit = new DigitalInput(armStopLimit_channel);
	isFlapOpen = false;
}

void StackingSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
bool StackingSubsystem::isPressed() {
	return armStopLimit->Get();
}
void StackingSubsystem::setOpen() {
	flapActuator->Set(DoubleSolenoid::kForward);
	isFlapOpen = true;
}
void StackingSubsystem::setClosed() {
	flapActuator->Set(DoubleSolenoid::kReverse);
	isFlapOpen = false;
}
bool StackingSubsystem::getFlapOpen() {
	return isFlapOpen;
}
