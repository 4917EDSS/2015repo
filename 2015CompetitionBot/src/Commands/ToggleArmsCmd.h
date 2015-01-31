#ifndef ToggleArmsCmd_H
#define ToggleArmsCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleArmsCmd: public CommandBase
{
public:
	ToggleArmsCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
