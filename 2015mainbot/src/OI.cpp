#include "OI.h"
#include "Commands/ToggleIntake.h"
#include "Commands/ArmMotorIntake.h"
#include "Commands/ArmMotorExpel.h"
#include "Commands/ToggleLift.h"
#include <cmath>

OI::OI() {
	leftStick = new Joystick(1);
	rightStick = new Joystick(2);
	Joystick* rightPhysicalStick;
	int liftButtonAssignment;
	if (CONTROLLER_TYPE==PLAYSTATION){
		rightPhysicalStick = leftStick;
		liftButtonAssignment = 4;
	}
	else if (CONTROLLER_TYPE==JOYSTICK) {
		rightPhysicalStick = rightStick;
		liftButtonAssignment = 1;
	}
	intakeToggleButton = new JoystickButton(leftStick, 1);
	intakeToggleButton->WhenPressed(new ToggleIntake());
	expelSpinButton = new JoystickButton(leftStick, 2);
	expelSpinButton->WhileHeld(new ArmMotorExpel());
	intakeSpinButton = new JoystickButton(leftStick, 3);
	intakeSpinButton->WhileHeld(new ArmMotorIntake());
	liftToggleButton = new JoystickButton(rightPhysicalStick, liftButtonAssignment);
	liftToggleButton->WhenPressed(new ToggleLift());
	// Process operator interface input here.
}
float OI::getRightStick(){
	if (CONTROLLER_TYPE==PLAYSTATION){
		return getStick(leftStick, 3);
	}
	else if (CONTROLLER_TYPE==JOYSTICK) {
		return getStick(rightStick, 2);
	}

}
float OI::getLeftStick(){
	if (CONTROLLER_TYPE==PLAYSTATION) {
		return getStick(leftStick, 1);
	}
	else if (CONTROLLER_TYPE==JOYSTICK){
		return getStick(leftStick, 2);
	}

}
float OI::getStick(Joystick* stick, int axis){
	float rawInput = stick->GetRawAxis(axis);
	return (rawInput*fabs(rawInput));
}
