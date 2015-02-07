#include "ToggleJawsCmd.h"

ToggleJawsCmd::ToggleJawsCmd()
{
	Requires(rLiftSub);
}

void ToggleJawsCmd::Initialize()
{
	rLiftSub->ToggleJaws();
}

void ToggleJawsCmd::Execute()
{
}

bool ToggleJawsCmd::IsFinished()
{
	return true;
}

void ToggleJawsCmd::End()
{
}

void ToggleJawsCmd::Interrupted()
{
}
