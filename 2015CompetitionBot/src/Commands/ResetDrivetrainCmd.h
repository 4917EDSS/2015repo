#ifndef ResetDrivetrainCmd_H
#define ResetDrivetrainCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetDrivetrainCmd: public CommandBase
{
public:
	ResetDrivetrainCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
