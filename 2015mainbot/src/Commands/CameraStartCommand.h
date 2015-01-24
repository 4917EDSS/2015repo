#ifndef CameraStartCommand_H
#define CameraStartCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class CameraStartCommand: public CommandBase
{
public:
	CameraStartCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
