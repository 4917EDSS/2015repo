#include "ResetLiftEncoderCmd.h"

ResetLiftEncoderCmd::ResetLiftEncoderCmd()
{

	Requires(rLiftSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ResetLiftEncoderCmd::Initialize()
{
	rLiftSub->LiftMotorDown(1);
}

// Called repeatedly when this Command is scheduled to run
void ResetLiftEncoderCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetLiftEncoderCmd::IsFinished()
{
	return rLiftSub->GetBottomLimitSwitch();
}

// Called once after isFinished returns true
void ResetLiftEncoderCmd::End()
{
	rLiftSub->LiftMotorDown(0);
	rLiftSub->ResetLift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetLiftEncoderCmd::Interrupted()
{
	End();
}
