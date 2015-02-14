#include "DriveStraightCmd.h"
#include "RobotParameters.h"

DriveStraightCmd::DriveStraightCmd(int driveDistanceMillimeters, float driveSpeedParam)
{
	driveSpeed = driveSpeedParam;
	if (driveSpeed > 0)
	{
		targetDistance = abs(driveDistanceMillimeters);
	}
	else
	{
		targetDistance = -abs(driveDistanceMillimeters);
	}
	currentDrive = 0;
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
	rDrivetrainSub->drive(driveSpeed, driveSpeed);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{
	if (driveSpeed > 0)
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
	else
	{
		if (rDrivetrainSub->GetRightEnc() < rDrivetrainSub->GetLeftEnc())
		{
			currentDrive = rDrivetrainSub->GetRightEnc();
		}
		else
		{
			currentDrive = rDrivetrainSub->GetLeftEnc();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	if (driveSpeed > 0)
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
	else
	{
		if (currentDrive <= targetDistance)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{
	rDrivetrainSub->drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{
	rDrivetrainSub->drive(0,0);
}
