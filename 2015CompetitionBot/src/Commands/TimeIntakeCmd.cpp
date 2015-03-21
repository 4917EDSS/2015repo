#include "TimeIntakeCmd.h"

int i;

TimeIntakeCmd::TimeIntakeCmd()
{
	Requires(rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void TimeIntakeCmd::Initialize()
{
	rIntakeSub->SetBeltsIn(0.5);
}

// Called repeatedly when this Command is scheduled to run
void TimeIntakeCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool TimeIntakeCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void TimeIntakeCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimeIntakeCmd::Interrupted()
{

}
