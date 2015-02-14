#include "DriveStraightCmd.h"
#include "RobotParameters.h"

DriveStraightCmd::DriveStraightCmd(int driveDistance)
{
	targetDistance = driveDistance;
	currentDrive = 0;
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
	rDrivetrainSub->Drive(1, 1);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{
	if (rDrivetrainSub->GetRightEnc() > rDrivetrainSub->GetLeftEnc())
	{
		currentDrive = rDrivetrainSub->GetRightEnc();
	}
	else
	{
		currentDrive = rDrivetrainSub->GetLeftEnc();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	if (currentDrive >= targetDistance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{
	rDrivetrainSub->Drive(0,0);
}
