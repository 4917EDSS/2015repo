#ifndef SET_LIFT_POSITION_COMMAND_H
#define SET_LIFT_POSITION_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author SetLiftPositionAuthor
 */
class SetLiftPositionCommand: public CommandBase {
private:
	float desiredPosition;
public:
	SetLiftPositionCommand(float position);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
