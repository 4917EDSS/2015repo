#include "OI.h"
#include "Commands/ToggleArmsCmd.h"
#include "Commands/ToggleLocksCmd.h"
#include "Commands/PickUpBoxGrp.h"
#include "Commands/IntakeUntilLimitCmd.h"
#include "Commands/ToggleJawsCmd.h"
//Remember to include Commands here.

OI::OI()
{
	dController = new Joystick(DControllerDriverPort);
	oController = new Joystick(OControllerOperatorPort);
	oIntakeToggleBtn = new JoystickButton(oController, OIntakeToggleBtn);
	oIntakeToggleBtn->WhenPressed(new ToggleArmsCmd());
	oLockToggleBtn = new JoystickButton(oController, OLockToggleBtn);
	oLockToggleBtn->WhenPressed(new ToggleLocksCmd());
	oToggleJawsBtn = new JoystickButton(oController, OToggleJawsBtn);
	oToggleJawsBtn->WhenPressed(new ToggleJawsCmd());
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
	oTestBtn = new JoystickButton(oController, OTestBtn);
	oTestBtn->WhenPressed (new IntakeUntilLimitCmd());
	// Process operator interface input here.
}

float OI::getStick(Joystick* controller, int axis){
	float rawInput = controller->GetRawAxis(axis);
	return (rawInput*fabs(rawInput));
}

//Controller vertical axis are inverted.
float OI::DGetRightVer(){
	return -getStick(dController, DRightVerticalAxis);
}

float OI::DGetLeftVer(){
	return -getStick(dController, DLeftVerticalAxis);
}

float OI::OGetRightVer(){
	return -getStick(oController, ORightVerticalAxis);
}

float OI::OGetLeftVer(){
	return -getStick(oController, OLeftVerticalAxis);
}

float OI::OGetLeftHor(){
	return getStick(oController, OLeftHorizontalAxis);
}

float OI::OGetRightHor(){
	return getStick(oController, ORightHorizontalAxis);
}
