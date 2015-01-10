#ifndef ARM_MOTOR_EXPEL_H
#define ARM_MOTOR_EXPEL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author DriveWithJoystickAuthor
 */
class ArmMotorExpel: public CommandBase {
public:
	ArmMotorExpel();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
