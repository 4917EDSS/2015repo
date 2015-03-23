#ifndef TimeIntakeCmd_H
#define TimeIntakeCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class StartIntakeCmd: public CommandBase
{
public:
	StartIntakeCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
