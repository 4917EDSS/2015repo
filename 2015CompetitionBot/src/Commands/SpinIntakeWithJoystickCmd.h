#ifndef SpinIntakeWithJoystickCmd_H
#define SpinIntakeWithJoystickCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SpinIntakeWithJoystickCmd: public CommandBase
{
public:
	SpinIntakeWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
