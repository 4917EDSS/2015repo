#ifndef TOGGLE_INTAKE_H
#define TOGGLE_INTAKE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ToggleIntake: public CommandBase {
public:
	ToggleIntake();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
