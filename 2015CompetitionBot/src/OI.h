#ifndef OI_H
#define OI_H

#include "WPILib.h"

//prefix o=operator, prefix d=driver

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
 * Select = 9
 * Start = 10
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
#define OToggleJawsBtn 8
#define OStackingBtn 7
#define OGrabStackBtn 9
#define ODropStackBtn 10

//These two buttons are used on both controllers.
#define ODEmergencyStopBtn1 11
#define ODEmergencyStopBtn2 12

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
	JoystickButton* oToggleJawsBtn;
	JoystickButton* oStartStackingBtn;
	JoystickButton* oLockToggleBtn;
	JoystickButton* oDropOnTwoStackBtn;
	JoystickButton* oDropOnThreeStackBtn;
	JoystickButton* oDropOnFourStackBtn;
	JoystickButton* oDropOnFiveStackBtn;
	JoystickButton* oDropStackBtn;
	JoystickButton* oGrabStackBtn;
	JoystickButton* oTestBtn;
	JoystickButton* oEmergencyStopBtn1;
	JoystickButton* oEmergencyStopBtn2;
	JoystickButton* dEmergencyStopBtn1;
	JoystickButton* dEmergencyStopBtn2;
	float getStick(Joystick* stick, int axis);

public:
	OI();
	float DGetRightVer();
	float DGetLeftVer();
	float OGetRightVer();
	float OGetLeftVer();
	float OGetLeftHor();
	float OGetRightHor();
};

#endif
