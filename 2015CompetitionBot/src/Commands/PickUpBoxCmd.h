#ifndef PickUpBoxCmd_H
#define PickUpBoxCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class PickUpBoxCmd: public CommandBase
{
public:
	PickUpBoxCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
