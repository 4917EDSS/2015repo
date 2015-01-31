#include "SetLocksCmd.h"

SetLocksCmd::SetLocksCmd(bool isOpen)
{
	lockPosition = isOpen;
	Requires(rLiftSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetLocksCmd::Initialize()
{
	rLiftSub->SetLocks(lockPosition);
}

// Called repeatedly when this Command is scheduled to run
void SetLocksCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetLocksCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetLocksCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLocksCmd::Interrupted()
{

}
