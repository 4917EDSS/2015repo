#ifndef AdjustPIDCmd_H
#define AdjustPIDCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AdjustPIDCmd: public CommandBase
{

public:
	AdjustPIDCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
