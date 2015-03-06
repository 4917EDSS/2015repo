#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DrivetrainSub* CommandBase::rDrivetrainSub = NULL;
IntakeSub* CommandBase::rIntakeSub = NULL;
LiftSub* CommandBase::rLiftSub = NULL;
CameraSub* CommandBase::rCameraSub = NULL;

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

	rDrivetrainSub = new DrivetrainSub(RightDrivePWM, LeftDrivePWM, LeftDriveEncoder1DIO, LeftDriveEncoder2DIO, RightDriveEncoder1DIO, RightDriveEncoder2DIO);
	rIntakeSub = new IntakeSub(ArmRightMotorPWM, ArmLeftMotorPWM, ArmsSolenoid1PNC, ArmsSolenoid2PNC, IntakeLimitSwitchDIO);
	rLiftSub = new LiftSub(LiftMotorPWM, LockSolenoid1PNC, LockSolenoid2PNC, JawsSolenoid1PNC, JawsSolenoid2PNC, LiftEncoder1DIO, LiftEncoder2DIO, TopLimitSwitchDIO, BottomLimitSwitchDIO);
	//rCameraSub = new CameraSub();






	//oi should be ALWAYS be the LAST subsystem initialized!
	oi = new OI();
}
