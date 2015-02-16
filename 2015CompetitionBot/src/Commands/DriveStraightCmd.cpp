#include "DriveStraightCmd.h"
#include "RobotParameters.h"

DriveStraightCmd::DriveStraightCmd(int driveDistanceMillimeters, float driveSpeedParam)
{
	leftSpeed = driveSpeedParam;
	rightSpeed = driveSpeedParam;
	forward = driveSpeedParam > 0;
	if (driveSpeedParam > 0)
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
	/*rDrivetrainSub->ResetDrive();
	rDrivetrainSub->Drive(leftSpeed, rightSpeed);*/
	rDrivetrainSub->EnablePID();
	rDrivetrainSub->SetRightSetpoint(targetDistance, rightSpeed);
	rDrivetrainSub->SetLeftSetpoint(targetDistance, leftSpeed);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{
	/*float averageSpeed = (leftSpeed + rightSpeed)/2;
>>>>>>> origin/master
	if (forward)
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
	currentDrive = (rDrivetrainSub->GetLeftEnc() + rDrivetrainSub->GetRightEnc())/2;
	rDrivetrainSub->Drive(leftSpeed, rightSpeed);*/
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	/*if (forward)
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
	}*/
	return rDrivetrainSub->isLeftOnTarget() && rDrivetrainSub->isRightOnTarget();

}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{
	rDrivetrainSub->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{
	rDrivetrainSub->Drive(0,0);
}
