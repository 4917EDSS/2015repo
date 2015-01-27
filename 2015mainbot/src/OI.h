#ifndef OI_H
#define OI_H

#include "WPILib.h"

/*
 * ON LOGITECH CONTROLLER:
 * X = 1
 * A = 2
 * B = 3
 * Y = 4
 * LB = 5
 * RB = 6
 * LT = 7
 * RT = 8
 * L3 = 11
 * R3 = 12
 * Left Vertical = 1
 * Left Horizontal = 0
 * Right Vertical = 3
 * Right Horizontal = 2
 *
 */
#define EXPEL_BUTTON 7
#define INTAKE_BUTTON 8
#define LIFT_RAISE_BUTTON 6
#define LIFT_LOWER_BUTTON 9
#define TOGGLE_FLAP_BUTTON 5
#define CONTROLLER_DRIVER_PORT 0
#define CONTROLLER_OPERATOR_PORT 1
#define INTAKE_TOGGLE_BUTTON 4
#define STACKER_BUTTON 2

//Axis
#define LEFT_VERTICAL 1
#define RIGHT_VERTICAL 3

class OI {
private:
	//prefix o=operator, prefix d=driver
	Joystick* dController;
	Joystick* oController;
	JoystickButton* dLiftDownButton;
	JoystickButton* dLiftUpButton;
	JoystickButton* dIntakeToggleButton;
	JoystickButton* dExpelSpinButton;
	JoystickButton* dIntakeSpinButton;
	JoystickButton* dStackBoxButton;
	JoystickButton* oIntakeToggleButton;
	JoystickButton* oToggleFlapButton;
	/*JoystickButton* boxZeroButton;
	JoystickButton* boxOneButton;
	JoystickButton* boxTwoButton;
	JoystickButton* boxThreeButton;
	JoystickButton* boxFourButton;*/
	float getStick(Joystick* stick, int axis);
public:
	OI();
	float getRightStick();
	float getLeftStick();
	float getRightOperatorStick();
	float getLeftOperatorStick();
};

#endif
