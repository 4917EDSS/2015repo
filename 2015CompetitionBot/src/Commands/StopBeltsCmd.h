#ifndef StopBeltsCmd_H
#define StopBeltsCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopBeltsCmd: public CommandBase
{
public:
	StopBeltsCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
