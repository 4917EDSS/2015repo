#ifndef TimeIntakeCmd_H
#define TimeIntakeCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class TimeIntakeCmd: public CommandBase
{
public:
	TimeIntakeCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
