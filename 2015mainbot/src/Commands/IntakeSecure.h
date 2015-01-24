#ifndef IntakeSecure_H
#define IntakeSecure_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeSecure: public CommandBase
{
public:
	IntakeSecure();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
