#include "DriveWithJoystickCmd.h"
#include "RobotParameters.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	previousRightSpeed = 0;
	previousLeftSpeed = 0;
	Requires(rDrivetrainSub);
	rDrivetrainSub->DisableTurnPID();
}

void DriveWithJoystickCmd::Initialize()
{
	rDrivetrainSub->EnableSpeedPID();
	rDrivetrainSub->DisableTurnPID();
}

void DriveWithJoystickCmd::Execute()
{
	if(rDrivetrainSub->GetControls() == TANK_DRIVE_CONTROLS)
	{
		if (oi->DGetLeftVer() - previousLeftSpeed > rDrivetrainSub->GetAccelThresh())
		{
			previousLeftSpeed += rDrivetrainSub->GetAccelThresh();
		}
		else if (oi->DGetLeftVer()-previousLeftSpeed < -rDrivetrainSub->GetAccelThresh())
		{
			previousLeftSpeed -= rDrivetrainSub->GetAccelThresh();
		}
		else
		{
			previousLeftSpeed = oi->DGetLeftVer();
		}

		if (oi->DGetRightVer()-previousRightSpeed > rDrivetrainSub->GetAccelThresh())
		{
			previousRightSpeed += rDrivetrainSub->GetAccelThresh();
		}
		else if (oi->DGetRightVer()-previousRightSpeed < -rDrivetrainSub->GetAccelThresh())
		{
			previousRightSpeed -= rDrivetrainSub->GetAccelThresh();
		}
		else
		{
			previousRightSpeed = oi->DGetRightVer();
		}

		rDrivetrainSub->DisableSpeedPID();
		rDrivetrainSub->Drive(oi->DGetLeftVer(), oi->DGetRightVer());
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
	}

	else
	{
		if (oi->DGetLeftVer()-previousLeftSpeed > rDrivetrainSub->GetAccelThresh())
		{
			previousLeftSpeed += rDrivetrainSub->GetAccelThresh();
		}
		else if (oi->DGetLeftVer()-previousLeftSpeed < -rDrivetrainSub->GetAccelThresh())
		{
			previousLeftSpeed -= rDrivetrainSub->GetAccelThresh();
		}
		else
		{
			previousLeftSpeed = oi->DGetLeftVer();
		}
		if (oi->DGetRightHor()-previousRightSpeed > rDrivetrainSub->GetAccelThresh())
		{
			previousRightSpeed += rDrivetrainSub->GetAccelThresh();
		}
		else if (oi->DGetRightHor()-previousRightSpeed < -rDrivetrainSub->GetAccelThresh())
		{
			previousRightSpeed -= rDrivetrainSub->GetAccelThresh();
		}
		else
		{
			previousRightSpeed = oi->DGetRightHor();
		}
#ifdef BYPASS_DRIVE_PID
		rDrivetrainSub->DisableSpeedPID();
		rDrivetrainSub->Drive(previousLeftSpeed + previousRightSpeed, previousLeftSpeed - previousRightSpeed);
#else
		rDrivetrainSub->EnableSpeedPID();
		rDrivetrainSub->PIDDrive(previousLeftSpeed + previousRightSpeed, previousLeftSpeed - previousRightSpeed);
#endif
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
	}
}

bool DriveWithJoystickCmd::IsFinished()
{
	return false;
}

void DriveWithJoystickCmd::End()
{
	rDrivetrainSub->DisableSpeedPID();
}

void DriveWithJoystickCmd::Interrupted()
{
	End();
}
