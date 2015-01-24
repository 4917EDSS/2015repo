#ifndef SpinIntakeWithJoystick_H
#define SpinIntakeWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class SpinIntakeWithJoystick: public CommandBase
{
public:
	SpinIntakeWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
