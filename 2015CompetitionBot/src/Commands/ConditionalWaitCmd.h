/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.                                                         */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef __CONDITIONAL_WAIT_CMD_H__
#define __CONDITIONAL_WAIT_CMD_H__

#include "Commands/Command.h"

class ConditionalWaitCmd : public Command
{
private:
	bool boxInIntake;
public:
	ConditionalWaitCmd(double timeout, bool boxInIntake);
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
