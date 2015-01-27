#ifndef FlapToggle_H
#define FlapToggle_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlapToggle: public CommandBase
{
public:
	FlapToggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
