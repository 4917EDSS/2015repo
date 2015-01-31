#ifndef MoveMastWithJoystickCmd_H
#define MoveMastWithJoystickCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveMastWithJoystickCmd: public CommandBase
{
public:
	MoveMastWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
