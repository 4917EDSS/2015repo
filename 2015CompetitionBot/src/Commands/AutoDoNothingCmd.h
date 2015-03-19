#ifndef AutoDoNothingCmd_H
#define AutoDoNothingCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDoNothingCmd: public CommandBase
{
public:
	AutoDoNothingCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
