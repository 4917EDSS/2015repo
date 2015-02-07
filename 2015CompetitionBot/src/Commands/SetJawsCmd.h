#ifndef SetJawsCmd_H
#define SetJawsCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetJawsCmd: public CommandBase
{
private:
	bool jawsPosition;
public:
	SetJawsCmd(bool isOpen);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
