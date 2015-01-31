#include "ToggleArmsCmd.h"

ToggleArmsCmd::ToggleArmsCmd()
{
	Requires(rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleArmsCmd::Initialize()
{
	rIntakeSub->SetArms(!rIntakeSub->GetArms());
}

// Called repeatedly when this Command is scheduled to run
void ToggleArmsCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleArmsCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleArmsCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleArmsCmd::Interrupted()
{

}
