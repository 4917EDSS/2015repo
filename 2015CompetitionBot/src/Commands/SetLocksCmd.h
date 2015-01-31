#ifndef SetLocksCmd_H
#define SetLocksCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetLocksCmd: public CommandBase
{
private:
	bool lockPosition;
public:
	SetLocksCmd(bool isOpen);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
