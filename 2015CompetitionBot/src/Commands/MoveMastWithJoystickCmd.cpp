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
	if (oi->OGetLeftVer() > 0)
	{
		rLiftSub->LiftMotorUp(oi->OGetLeftVer());
	}

	else
	{
		rLiftSub->LiftMotorDown(oi->OGetLeftVer());
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
