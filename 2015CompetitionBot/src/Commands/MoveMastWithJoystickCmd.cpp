#include "MoveMastWithJoystickCmd.h"

MoveMastWithJoystickCmd::MoveMastWithJoystickCmd()
{
	Requires(rLiftSub);
}

void MoveMastWithJoystickCmd::Initialize()
{
}

void MoveMastWithJoystickCmd::Execute()
{
	if (oi->OGetRightVer() > 0)
	{
		rLiftSub->LiftMotorUp(oi->OGetRightVer());
	}

	else
	{
		rLiftSub->LiftMotorDown(oi->OGetRightVer());
	}
}

bool MoveMastWithJoystickCmd::IsFinished()
{
	return false;
}

void MoveMastWithJoystickCmd::End()
{
}

void MoveMastWithJoystickCmd::Interrupted()
{
	rLiftSub->LiftMotorUp(0.0);
}
