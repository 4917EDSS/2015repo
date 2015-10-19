#include "ToggleConJawCmd.h"

ToggleConJawCmd::ToggleConJawCmd()
{
	Requires(rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleConJawCmd::Initialize()
{
	rIntakeSub->SetConJaw(!rIntakeSub->GetConJaw());
}

// Called repeatedly when this Command is scheduled to run
void ToggleConJawCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleConJawCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleConJawCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleConJawCmd::Interrupted()
{

}
