#include "OI.h"
//Remember to include Commands here.

OI::OI()
{
	dController = new Joystick(DControllerDriverPort);
	oController = new Joystick(OControllerOperatorPort);
	oIntakeToggleBtn = new JoystickButton(oController, OIntakeToggleBtn);
	oIntakeToggleBtn->WhenPressed(new ToggleArmsCmd());
	oLockToggleBtn = new JoystickButton(oController, OLockToggleBtn);
	oLockToggleBtn->WhenPressed(new ToggleLocksCmd());
	oDropStackBtn = new JoystickButton(oController, ODropStackBtn);
	//Command here.
	oStartStackingBtn = new JoystickButton(oController, OStackingBtn);
	oStartStackingBtn->WhenPressed(new PickUpBoxGrp());
	oDropOnTwoStackBtn = new JoystickButton(oController, ODropOnTwoStackBtn);
	//Command here.
	oDropOnThreeStackBtn = new JoystickButton(oController, ODropOnThreeStackBtn);
	//Command here.
	oDropOnFourStackBtn = new JoystickButton(oController, ODropOnFourStackBtn);
	//Command here.
	oDropOnFiveStackBtn = new JoystickButton(oController, ODropOnFiveStackBtn);
	//Command here.

	// Process operator interface input here.
}
float OI::getStick(Joystick* controller, int axis){
		float rawInput = controller->GetRawAxis(axis);
		return (rawInput*fabs(rawInput));
	}
	float OI::getRightStick(){
		return getStick(dController, DRightVerticalAxis);
	}
	float OI::getLeftStick(){
		return getStick(dController, DLeftVerticalAxis);
	}

	float OI::getRightOperatorStick(){
		return getStick(oController, ORightVerticalAxis);
	}
	float OI::getLeftOperatorStick(){
		return getStick(oController, OLeftVerticalAxis);
	}
	float OI::getLeftOperatorHorizontalStick(){
		return getStick(oController, OLeftHorizontalAxis);
	}
