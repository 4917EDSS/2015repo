#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DrivetrainSub* CommandBase::rDrivetrainSub = NULL;
IntakeSub* CommandBase::rIntakeSub = NULL;
LiftSub* CommandBase::rLiftSub = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.

	oi = new OI();
	rDrivetrainSub = new DrivetrainSub(RightDrive1PWM, RightDrive2PWM, LeftDrive1PWM, LeftDrive2PWM);
	rIntakeSub = new IntakeSub(ArmRightMotorPWM, ArmLeftMotorPWM, ArmsSolenoid1PNC, ArmsSolenoid2PNC, IntakeLimitSwitchDIO);
	rLiftSub = new LiftSub(LiftMotorPWM, LockSolenoid1PNC, LockSolenoid2PNC, Encoder1DIO, Encoder2DIO);
}
