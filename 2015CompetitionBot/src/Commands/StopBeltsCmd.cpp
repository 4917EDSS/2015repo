#include "StopBeltsCmd.h"

StopBeltsCmd::StopBeltsCmd()
{
	Requires(rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void StopBeltsCmd::Initialize()
{
	rIntakeSub->SetBelts(0.0, 0.0);
}

// Called repeatedly when this Command is scheduled to run
void StopBeltsCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopBeltsCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StopBeltsCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopBeltsCmd::Interrupted()
{

}
