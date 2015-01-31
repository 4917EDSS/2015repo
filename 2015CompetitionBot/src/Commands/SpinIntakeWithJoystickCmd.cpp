#include "SpinIntakeWithJoystickCmd.h"

SpinIntakeWithJoystickCmd::SpinIntakeWithJoystickCmd()
{
	Requires(rIntakeSub);
}

void SpinIntakeWithJoystickCmd::Initialize()
{
}

void SpinIntakeWithJoystickCmd::Execute()
{
	if (oi->OGetLeftHor() > CONTROLLER_HOR_INTAKE_TOLERANCE)
	{
		rIntake->SetBeltsRight(oi->OGetLeftHor());
	}

	else if (oi->OGetLeftHor() < -CONTROLLER_HOR_INTAKE_TOLERANCE)
	{
		rIntake->SetBeltsLeft(-oi->OGetLeftHor());
	}

	else
	{
		rIntake->SetBeltsIn(oi->OGetLeftVer());
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
