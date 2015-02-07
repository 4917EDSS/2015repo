#ifndef ToggleJawsCmd_H
#define ToggleJawsCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleJawsCmd: public CommandBase
{
public:
	ToggleJawsCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
