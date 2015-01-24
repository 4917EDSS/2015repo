#ifndef BoxHandoff_H
#define BoxHandoff_H

#include "../CommandBase.h"
#include "WPILib.h"

class BoxHandoff: public CommandBase
{
public:
	BoxHandoff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
