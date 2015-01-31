#include "SetLiftHeightCmd.h"

SetLiftHeightCmd::SetLiftHeightCmd(int destination)
{
	height = destination;
	Requires (rLiftSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetLiftHeightCmd::Initialize()
{
	rLiftSub->SetArmsTarget(height);
}

// Called repeatedly when this Command is scheduled to run
void SetLiftHeightCmd::Execute()
{
	rLiftSub->Update();
}

// Make this return true when this Command no longer needs to run execute()
bool SetLiftHeightCmd::IsFinished()
{
	return rLiftSub->IsOnTarget();
}

// Called once after isFinished returns true
void SetLiftHeightCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLiftHeightCmd::Interrupted()
{

}
