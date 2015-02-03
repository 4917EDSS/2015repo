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
	rDrivetrainSub->drive(oi->DGetLeftVer(), oi->DGetRightVer());
	SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
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
