#include "IntakeUntilLimitCmd.h"

IntakeUntilLimitCmd::IntakeUntilLimitCmd()
{
	Requires (rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void IntakeUntilLimitCmd::Initialize()
{
	rIntakeSub->BeltsIn(1);
}

// Called repeatedly when this Command is scheduled to run
void IntakeUntilLimitCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeUntilLimitCmd::IsFinished()
{
	return rIntakeSub->IsLimmitHit();
}

// Called once after isFinished returns true
void IntakeUntilLimitCmd::End()
{
	rIntakeSub->BeltsIn(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeUntilLimitCmd::Interrupted()
{

}
