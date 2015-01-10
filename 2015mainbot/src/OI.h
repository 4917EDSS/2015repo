#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	JoystickButton* goForward;
	JoystickButton* intakeToggleButton;
	JoystickButton* expelSpinButton;
	JoystickButton* intakeSpinButton;

public:
	Joystick *leftStick;
	Joystick *rightStick;
	OI();
	Joystick *GetRightStick();
	Joystick *GetLeftStick();
};

#endif
