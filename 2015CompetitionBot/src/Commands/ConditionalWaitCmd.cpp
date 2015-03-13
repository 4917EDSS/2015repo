/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.                                                         */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "ConditionalWaitCmd.h"
#include "RobotParameters.h"
#include <sstream>

ConditionalWaitCmd::ConditionalWaitCmd(double timeout, bool boxInIntake) :
	Command(((std::stringstream&)(std::stringstream("Wait(") << timeout << ")")).str().c_str(), timeout)
{
}

void ConditionalWaitCmd::Initialize()
{
}

void ConditionalWaitCmd::Execute()
{
}

bool ConditionalWaitCmd::IsFinished()
{
	if (boxInIntake){
		return IsTimedOut();
	}
	else
	{
		return true;
	}
}

void ConditionalWaitCmd::End()
{
}

void ConditionalWaitCmd::Interrupted()
{
}
