#include "ToggleLocksCmd.h"

ToggleLocksCmd::ToggleLocksCmd()
{
	Requires(rLiftSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleLocksCmd::Initialize()
{
	rLiftSub->ToggleLocks();
}

// Called repeatedly when this Command is scheduled to run
void ToggleLocksCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLocksCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleLocksCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLocksCmd::Interrupted()
{

}
