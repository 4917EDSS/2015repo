#include "OI.h"
#include "Commands/ToggleIntake.h"
#include "Commands/ArmMotorIntake.h"
#include "Commands/ArmMotorExpel.h"

OI::OI() {
	leftStick = new Joystick(1);
	rightStick = new Joystick(2);
	intakeToggleButton = new JoystickButton(leftStick, 1);
	intakeToggleButton->WhenPressed(new ToggleIntake());
	expelSpinButton = new JoystickButton(leftStick, 2);
	expelSpinButton->WhileHeld(new ArmMotorExpel());
	intakeSpinButton = new JoystickButton(leftStick, 3);
	intakeSpinButton->WhileHeld(new ArmMotorIntake());
	
	// Process operator interface input here.
}
Joystick* OI:: GetRightStick(){
	return rightStick;
}
Joystick* OI::GetLeftStick(){
	return leftStick;
}
