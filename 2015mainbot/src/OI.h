#ifndef OI_H
#define OI_H

#include "WPILib.h"

//match the CONTROLLER_TYPE's number to joystick or playstation number
#define JOYSTICK 1
#define PLAYSTATION 2
#define CONTROLLER_TYPE 2

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	JoystickButton* liftToggleButton;
	JoystickButton* intakeToggleButton;
	JoystickButton* expelSpinButton;
	JoystickButton* intakeSpinButton;
	float getStick(Joystick* stick, int axis);
public:
	OI();
	float getRightStick();
	float getLeftStick();
};

#endif
