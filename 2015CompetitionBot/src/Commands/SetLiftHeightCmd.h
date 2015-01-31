#ifndef SetLiftHeightCmd_H
#define SetLiftHeightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetLiftHeightCmd: public CommandBase
{
private:
	int height;
public:
	SetLiftHeightCmd(int destination);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
