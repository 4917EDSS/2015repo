#ifndef DRIVE_WITH_JOYSTICK_COMMAND_H
#define DRIVE_WITH_JOYSTICK_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author DriveWithJoystickAuthor
 */
class DriveWithJoystickCommand: public CommandBase {
public:
	DriveWithJoystickCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
