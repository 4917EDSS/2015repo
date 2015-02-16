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
	rDrivetrainSub->DisablePID();
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
		rDrivetrainSub->Drive(previousLeftSpeed, previousRightSpeed);
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
		rDrivetrainSub->Drive(previousLeftSpeed + oi->DGetRightHor(), previousLeftSpeed - oi->DGetRightHor());
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
	}
}

bool DriveWithJoystickCmd::IsFinished()
{
	return false;
}

void DriveWithJoystickCmd::End()
{
}

void DriveWithJoystickCmd::Interrupted()
{
}
