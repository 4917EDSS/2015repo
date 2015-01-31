#ifndef SetArmsCmd_H
#define SetArmsCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetArmsCmd: public CommandBase
{
public:
	SetArmsCmd(bool armsIn);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool armState;
};

#endif
