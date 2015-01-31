#ifndef ToggleLocksCmd_H
#define ToggleLocksCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleLocksCmd: public CommandBase
{
public:
	ToggleLocksCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
