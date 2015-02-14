#include "DriveWithJoystickCmd.h"
#include "RobotParameters.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	Requires(rDrivetrainSub);
}

void DriveWithJoystickCmd::Initialize()
{
}

void DriveWithJoystickCmd::Execute()
{
	if(rDrivetrainSub->GetControls() == TANK_DRIVE_CONTROLS)
	{
		rDrivetrainSub->Drive(oi->DGetLeftVer(), oi->DGetRightVer());
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
	}

	else
	{
		rDrivetrainSub->Drive(oi->DGetLeftVer() + oi->DGetRightHor(), oi->DGetLeftVer() - oi->DGetRightHor());
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
