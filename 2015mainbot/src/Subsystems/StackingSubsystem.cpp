#include "StackingSubsystem.h"
#include "../RobotMap.h"

StackingSubsystem::StackingSubsystem(int secondaryarm_channel1, int secondaryarm_channel2, int armStopLimit_channel):
		Subsystem("StackingSubsystem")
{
	secondaryArms = new GeneralAirToggle(secondaryarm_channel1, secondaryarm_channel2);
	armStopLimit = new DigitalInput(armStopLimit_channel);
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
	secondaryArms->set(true);
}
void StackingSubsystem::setClosed() {
	secondaryArms->set(false);
}
