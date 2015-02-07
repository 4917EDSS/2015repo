#include "SetJawsCmd.h"

SetJawsCmd::SetJawsCmd(bool isOpen)
{
	jawsPosition = isOpen;
	Requires(rLiftSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetJawsCmd::Initialize()
{
	rLiftSub->SetJaws(jawsPosition);
}

// Called repeatedly when this Command is scheduled to run
void SetJawsCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetJawsCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetJawsCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetJawsCmd::Interrupted()
{

}
