#ifndef ARM_MOTOR_INTAKE_H
#define ARM_MOTOR_INTAKE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author DriveWithJoystickAuthor
 */
class ArmMotorIntake: public CommandBase {
public:
	ArmMotorIntake();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
