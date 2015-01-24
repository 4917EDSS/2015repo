#ifndef AddBoxToStack_H
#define AddBoxToStack_H

#include "../CommandBase.h"
#include "WPILib.h"

class AddBoxToStack: public CommandBase
{
public:
	AddBoxToStack();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
