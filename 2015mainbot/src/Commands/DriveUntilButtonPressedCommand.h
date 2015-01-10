#ifndef DRIVE_UNTIL_BUTTON_PRESSED_COMMAND_H
#define DRIVE_UNTIL_BUTTON_PRESSED_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author DriveUntilButtonPressedAuthor
 */
class DriveUntilButtonPressedCommand: public CommandBase {
public:
	DriveUntilButtonPressedCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
