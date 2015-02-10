#include "SpinIntakeWithJoystickCmd.h"
#include "RobotParameters.h"

SpinIntakeWithJoystickCmd::SpinIntakeWithJoystickCmd()
{
	Requires(rIntakeSub);
	if (rIntakeSub==NULL) {
		printf("\n\n\n\nohhh nooo \n\n\n");
	}
	else {
		printf("\n\n\ngood\n\n\n");
	}
}

void SpinIntakeWithJoystickCmd::Initialize()
{
}

void SpinIntakeWithJoystickCmd::Execute()
{
	//printf("Default command");
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
		rIntakeSub->SetBeltsIn(-oi->OGetRightVer());
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
	printf("SpinIntakeW/Jscmd interrupt \n");
	rIntakeSub->SetBeltsIn(0.0);
}
