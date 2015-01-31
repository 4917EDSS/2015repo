#ifndef OI_H
#define OI_H
//prefix o=operator, prefix d=driver
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
//Controllers
#define DControllerDriverPort 0
#define OControllerOperatorPort 1

//Buttons
#define ODropOnTwoStackBtn 2
#define ODropOnThreeStackBtn 1
#define ODropOnFourStackBtn 3
#define ODropOnFiveStackBtn 4
#define OIntakeToggleBtn 5
#define OLockToggleBtn 6
#define ODropStackBtn 7
#define OStackingBtn 8


//Axis
#define ORightVerticalAxis 3
#define OLeftVerticalAxis 1
#define ORightHorizontalAxis 2
#define OLeftHorizontalAxis 0

#define DRightVerticalAxis 3
#define DLeftVerticalAxis 1
#define DRightHorizontalAxis 2
#define DLeftHorizontalAxis 0
class OI
{
private:

	Joystick* dController;
	Joystick* oController;
	JoystickButton* oIntakeToggleBtn;
	JoystickButton* oDropStackBtn;
	JoystickButton* oStartStackingBtn;
	JoystickButton* oLockToggleBtn;
	JoystickButton* oDropOnTwoStackBtn;
	JoystickButton* oDropOnThreeStackBtn;
	JoystickButton* oDropOnFourStackBtn;
	JoystickButton* oDropOnFiveStackBtn;
	float getStick(Joystick* stick, int axis);

public:
	OI();
	float getRightStick();
	float getLeftStick();
	float getRightOperatorStick();
	float getLeftOperatorStick();
	float getLeftOperatorHorizontalStick();
};

#endif
