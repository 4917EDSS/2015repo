#include "StartIntakeCmd.h"

int i;

StartIntakeCmd::StartIntakeCmd()
{
	Requires(rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void StartIntakeCmd::Initialize()
{
	rIntakeSub->SetBeltsIn(0.5);
}

// Called repeatedly when this Command is scheduled to run
void StartIntakeCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StartIntakeCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StartIntakeCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StartIntakeCmd::Interrupted()
{

}
