#ifndef ToggleDriveStyleCmd_H
#define ToggleDriveStyleCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleDriveStyleCmd: public CommandBase
{
public:
	ToggleDriveStyleCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
