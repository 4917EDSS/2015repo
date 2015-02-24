#include "DriveWithJoystickCmd.h"
#include "RobotParameters.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	previousRightSpeed = 0;
	previousLeftSpeed = 0;
	Requires(rDrivetrainSub);
}

void DriveWithJoystickCmd::Initialize()
{
	rDrivetrainSub->EnablePID();
}

void DriveWithJoystickCmd::Execute()
{
	if(rDrivetrainSub->GetControls() == TANK_DRIVE_CONTROLS)
	{/*
		if (oi->DGetLeftVer() - previousLeftSpeed > ACCELERATION_THRESHOLD)
		{
			previousLeftSpeed += ACCELERATION_THRESHOLD;
		}
		else if (oi->DGetLeftVer()-previousLeftSpeed < -ACCELERATION_THRESHOLD)
		{
			previousLeftSpeed -= ACCELERATION_THRESHOLD;
		}
		else
		{
			previousLeftSpeed = oi->DGetLeftVer();
		}

		if (oi->DGetRightVer()-previousRightSpeed > ACCELERATION_THRESHOLD)
		{
			previousRightSpeed += ACCELERATION_THRESHOLD;
		}
		else if (oi->DGetRightVer()-previousRightSpeed < -ACCELERATION_THRESHOLD)
		{
			previousRightSpeed -= ACCELERATION_THRESHOLD;
		}
		else
		{
			previousRightSpeed = oi->DGetRightVer();
		}*/
		rDrivetrainSub->PIDDrive(oi->DGetLeftVer(), oi->DGetRightVer());
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
	}

	else
	{/*
		if (oi->DGetLeftVer()-previousLeftSpeed > ACCELERATION_THRESHOLD)
		{
			previousLeftSpeed += ACCELERATION_THRESHOLD;
		}
		else if (oi->DGetLeftVer()-previousLeftSpeed < -ACCELERATION_THRESHOLD)
		{
			previousLeftSpeed -= ACCELERATION_THRESHOLD;
		}
		else
		{
			previousLeftSpeed = oi->DGetLeftVer();
		}*/
		rDrivetrainSub->PIDDrive(oi->DGetLeftVer() + oi->DGetRightHor(), oi->DGetLeftVer() - oi->DGetRightHor());
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
	}
}

bool DriveWithJoystickCmd::IsFinished()
{
	return false;
}

void DriveWithJoystickCmd::End()
{
	rDrivetrainSub->DisablePID();
}

void DriveWithJoystickCmd::Interrupted()
{
	End();
}
