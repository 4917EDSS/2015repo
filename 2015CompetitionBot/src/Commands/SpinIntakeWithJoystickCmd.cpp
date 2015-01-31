#include "SpinIntakeWithJoystickCmd.h"
#include "RobotParameters.h"

SpinIntakeWithJoystickCmd::SpinIntakeWithJoystickCmd()
{
	Requires(rIntakeSub);
}

void SpinIntakeWithJoystickCmd::Initialize()
{
}

void SpinIntakeWithJoystickCmd::Execute()
{
	if (oi->OGetRightHor() > CTRLR_HOR_INTAKE_TOLERANCE)
	{
		rIntakeSub->SetBeltsRight(oi->OGetRightHor());
	}

	else if (oi->OGetRightHor() < -CTRLR_HOR_INTAKE_TOLERANCE)
	{
		rIntakeSub->SetBeltsRight(oi->OGetRightHor());
	}

	else
	{
		rIntakeSub->SetBeltsIn(oi->OGetRightVer());
	}
}

bool SpinIntakeWithJoystickCmd::IsFinished()
{
	return false;
}

void SpinIntakeWithJoystickCmd::End()
{
}

void SpinIntakeWithJoystickCmd::Interrupted()
{
	rIntakeSub->SetBeltsIn(0.0);
}
