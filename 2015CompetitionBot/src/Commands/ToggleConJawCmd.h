#ifndef ToggleConJawCmd_H
#define ToggleConJawCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleConJawCmd: public CommandBase
{
public:
	ToggleConJawCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
