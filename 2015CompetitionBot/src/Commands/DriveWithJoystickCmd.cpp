#include "DriveWithJoystickCmd.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	Requires(rDrivetrainSub);
}

void DriveWithJoystickCmd::Initialize()
{
}

void DriveWithJoystickCmd::Execute()
{
	rDrivetrainSub->drive(oi->DGetRightVer(), oi->DGetLeftVer());
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
