#ifndef AutoLiftBinCmd_H
#define AutoLiftBinCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoLiftBinCmd: public CommandBase
{
public:
	AutoLiftBinCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
