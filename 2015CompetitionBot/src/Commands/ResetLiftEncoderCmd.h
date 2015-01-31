#ifndef ResetLiftEncoderCmd_H
#define ResetLiftEncoderCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetLiftEncoderCmd: public CommandBase
{
public:
	ResetLiftEncoderCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
