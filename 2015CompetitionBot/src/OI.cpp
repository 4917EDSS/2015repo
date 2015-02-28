#include "OI.h"
#include "Commands/ToggleArmsCmd.h"
#include "Commands/ToggleLocksCmd.h"
#include "Commands/PickUpBoxGrp.h"
#include "Commands/PickUpBoxCmd.h"
#include "Commands/IntakeUntilLimitCmd.h"
#include "Commands/ToggleJawsCmd.h"
#include "Commands/SetLiftHeightCmd.h"
#include "Commands/DropStackGrp.h"
#include "Commands/EmergencyStopCmd.h"
#include "Commands/ToggleDriveStyleCmd.h"
#include "Commands/QuickStackGrp.h"
#include "Commands/DropLockStackGrp.h"
#include "RobotParameters.h"


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
	oStartStackingBtn->WhenPressed(new PickUpBoxCmd());
	oDropOnTwoStackBtn = new JoystickButton(oController, ODropOnTwoStackBtn);
	oDropOnTwoStackBtn->WhenPressed(new SetLiftHeightCmd(TWO_STACK_EV));
	oDropOnThreeStackBtn = new JoystickButton(oController, ODropOnThreeStackBtn);
	oDropOnThreeStackBtn->WhenPressed(new SetLiftHeightCmd(THREE_STACK_EV));
	oDropOnFourStackBtn = new JoystickButton(oController, ODropOnFourStackBtn);
	oDropOnFourStackBtn->WhenPressed(new SetLiftHeightCmd(FOUR_STACK_EV));
	oDropOnFiveStackBtn = new JoystickButton(oController, ODropOnFiveStackBtn);
	oDropOnFiveStackBtn->WhenPressed(new SetLiftHeightCmd(FIVE_STACK_EV));
	oDropStackBtn = new JoystickButton(oController, ODropStackBtn);
	oDropStackBtn->WhenPressed(new DropStackGrp());
	oDropLockStackBtn = new JoystickButton(oController, ODropLockStackBtn);
	oDropLockStackBtn->WhenPressed(new DropLockStackGrp());
	dToggleDriveControlBtn = new JoystickButton(dController, DToggleDriveControlBtn);
	dToggleDriveControlBtn->WhenPressed(new ToggleDriveStyleCmd());
	oEmergencyStopBtn1 = new JoystickButton(oController, ODEmergencyStopBtn1);
	oEmergencyStopBtn1->WhenPressed(new EmergencyStopCmd());
	oQuickStackBtn = new JoystickButton(oController, OQuickStackBtn);
	oQuickStackBtn ->WhenPressed(new QuickStackGrp());
	dEmergencyStopBtn1 = new JoystickButton(dController, ODEmergencyStopBtn1);
	dEmergencyStopBtn1->WhenPressed(new EmergencyStopCmd());
	dEmergencyStopBtn2 = new JoystickButton(dController, ODEmergencyStopBtn2);
	dEmergencyStopBtn2->WhenPressed(new EmergencyStopCmd());
	//oTestBtn = new JoystickButton(oController, OTestBtn);
	//oTestBtn->WhenPressed (new IntakeUntilLimitCmd());
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

float OI::DGetLeftHor(){
	return getStick(dController, DLeftHorizontalAxis);
}

float OI::DGetRightHor(){
	return getStick(dController, DRightHorizontalAxis);
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
