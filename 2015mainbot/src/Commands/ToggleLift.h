#ifndef TOGGLE_LIFT_H
#define TOGGLE_LIFT_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ToggleLift: public CommandBase {
public:
	ToggleLift();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
