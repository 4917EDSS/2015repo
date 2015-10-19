#ifndef AdjustAccelThreshCmd_H
#define AdjustAccelThreshCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AdjustAccelThreshCmd: public CommandBase
{
public:
	AdjustAccelThreshCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
