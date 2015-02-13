#include "EmergencyStopCmd.h"

EmergencyStopCmd::EmergencyStopCmd()
{
	Requires(rDrivetrainSub);
	Requires(rIntakeSub);
	Requires(rLiftSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void EmergencyStopCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void EmergencyStopCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EmergencyStopCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EmergencyStopCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EmergencyStopCmd::Interrupted()
{

}
