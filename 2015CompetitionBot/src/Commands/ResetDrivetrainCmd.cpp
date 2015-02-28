#include "ResetDrivetrainCmd.h"

ResetDrivetrainCmd::ResetDrivetrainCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(rDrivetrainSub);
}

// Called just before this Command runs the first time
void ResetDrivetrainCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
}

// Called repeatedly when this Command is scheduled to run
void ResetDrivetrainCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetDrivetrainCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetDrivetrainCmd::End()
{
	rDrivetrainSub->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetDrivetrainCmd::Interrupted()
{
	rDrivetrainSub->Drive(0,0);
}
