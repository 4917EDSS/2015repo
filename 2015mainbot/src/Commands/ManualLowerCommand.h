#ifndef MANUAL_LOWER_COMMAND_H
#define MANUAL_LOWER_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ManualLowerAuthor
 */
class ManualLowerCommand: public CommandBase {
public:
	ManualLowerCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
