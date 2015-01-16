#ifndef MANUAL_RAISE_COMMAND_H
#define MANUAL_RAISE_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ManualRaiseAuthor
 */
class ManualRaiseCommand: public CommandBase {
public:
	ManualRaiseCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
