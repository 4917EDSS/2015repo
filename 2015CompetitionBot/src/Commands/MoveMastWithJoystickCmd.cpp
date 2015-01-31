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
	rLiftSub->LiftMotorUp(oi->OGetLeftVer());
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
