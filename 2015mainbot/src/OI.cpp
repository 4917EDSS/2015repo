#include "OI.h"
#include "RobotParameters.h"
#include "Commands/ToggleIntake.h"
#include "Commands/ArmMotorIntake.h"
#include "Commands/ArmMotorExpel.h"
#include "Commands/ManualRaiseCommand.h"
#include "Commands/ManualLowerCommand.h"
#include "Commands/SetLiftPositionCommand.h"
#include "Commands/StackBox.h"
#include "Commands/SpinIntakeWithJoystick.h"
#include "Commands/IntakeSecure.h"
#include <cmath>
#include "Commands/FlapToggle.h"

OI::OI() {
	dController = new Joystick(CONTROLLER_DRIVER_PORT);
	oController = new Joystick(CONTROLLER_OPERATOR_PORT);
	/*dIntakeToggleButton = new JoystickButton(dController, INTAKE_TOGGLE_BUTTON);
	dIntakeToggleButton->WhenPressed(new ToggleIntake());
	dExpelSpinButton = new JoystickButton(dController, EXPEL_BUTTON);
	dExpelSpinButton->WhileHeld(new ArmMotorExpel());
	dIntakeSpinButton = new JoystickButton(dController, INTAKE_BUTTON);
	dIntakeSpinButton->WhileHeld(new ArmMotorIntake());
	dLiftUpButton = new JoystickButton(dController, LIFT_RAISE_BUTTON);
	dLiftUpButton->WhileHeld(new ManualRaiseCommand());
	dLiftDownButton = new JoystickButton(dController, LIFT_LOWER_BUTTON);
	dLiftDownButton->WhileHeld(new ManualLowerCommand());
	dStackBoxButton = new JoystickButton(dController, STACKER_BUTTON);
	dStackBoxButton->WhenPressed(new StackBox());*/
	oIntakeToggleButton = new JoystickButton(oController, INTAKE_TOGGLE_BUTTON);
	oIntakeToggleButton->WhenPressed(new ToggleIntake());
	oToggleFlapButton = new JoystickButton(oController, TOGGLE_FLAP_BUTTON);
	oToggleFlapButton->WhenPressed(new FlapToggle());

}
float OI::getStick(Joystick* controller, int axis){
	float rawInput = controller->GetRawAxis(axis);
	return (rawInput*fabs(rawInput));
}
float OI::getRightStick(){
	return getStick(dController, RIGHT_VERTICAL);
}
float OI::getLeftStick(){
	return getStick(dController, LEFT_VERTICAL);
}

float OI::getRightOperatorStick(){
	return getStick(oController, RIGHT_VERTICAL);
}
float OI::getLeftOperatorStick(){
	return getStick(oController, LEFT_VERTICAL);
}
float OI::getRightOperatorHorizontalStick(){
	return getStick(oController, RIGHT_HORIZONTAL);
}
