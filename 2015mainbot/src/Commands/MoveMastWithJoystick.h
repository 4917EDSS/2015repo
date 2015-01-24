#ifndef MoveMastWithJoystick_H
#define MoveMastWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveMastWithJoystick: public CommandBase
{
public:
	MoveMastWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
