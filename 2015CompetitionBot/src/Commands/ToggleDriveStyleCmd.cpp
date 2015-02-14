#include "ToggleDriveStyleCmd.h"

ToggleDriveStyleCmd::ToggleDriveStyleCmd()
{
}

void ToggleDriveStyleCmd::Initialize()
{
	rDrivetrainSub-> ToggleControls();
}

void ToggleDriveStyleCmd::Execute()
{
}

bool ToggleDriveStyleCmd::IsFinished()
{
	return true;
}

void ToggleDriveStyleCmd::End()
{
}

void ToggleDriveStyleCmd::Interrupted()
{
}
