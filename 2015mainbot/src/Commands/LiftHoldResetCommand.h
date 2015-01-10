#ifndef LIFT_HOLD_RESET_COMMAND_H
#define LIFT_HOLD_RESET_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class LiftHoldResetCommand: public CommandBase {
public:
	LiftHoldResetCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
