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
		}

		rDrivetrainSub->DisableSpeedPID();
		rDrivetrainSub->Drive(oi->DGetLeftVer(), oi->DGetRightVer());
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
	}

	else
	{
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
		}
		if (oi->DGetRightHor()-previousRightSpeed > ACCELERATION_THRESHOLD)
		{
			previousRightSpeed += ACCELERATION_THRESHOLD;
		}
		else if (oi->DGetRightHor()-previousRightSpeed < -ACCELERATION_THRESHOLD)
		{
			previousRightSpeed -= ACCELERATION_THRESHOLD;
		}
		else
		{
			previousRightSpeed = oi->DGetRightHor();
		}
		rDrivetrainSub->EnableSpeedPID();
		rDrivetrainSub->PIDDrive(previousLeftSpeed + previousRightSpeed, previousLeftSpeed - previousRightSpeed);
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
