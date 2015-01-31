#ifndef IntakeUntilLimitCmd_H
#define IntakeUntilLimitCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeUntilLimitCmd: public CommandBase
{
public:
	IntakeUntilLimitCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
