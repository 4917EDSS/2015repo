#include "SetArmsCmd.h"

SetArmsCmd::SetArmsCmd(bool armsIn)
{
	Requires (rIntakeSub);
	armState = armsIn;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetArmsCmd::Initialize()
{
	rIntakeSub->SetArms(armState);
}

// Called repeatedly when this Command is scheduled to run
void SetArmsCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetArmsCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetArmsCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArmsCmd::Interrupted()
{

}
