#include "AutoDoNothingCmd.h"

AutoDoNothingCmd::AutoDoNothingCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoDoNothingCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDoNothingCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDoNothingCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoDoNothingCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDoNothingCmd::Interrupted()
{

}
