#include "OI.h"
#include "RobotParameters.h"
#include "Commands/ToggleIntake.h"
#include "Commands/ArmMotorIntake.h"
#include "Commands/ArmMotorExpel.h"
#include "Commands/ManualRaiseCommand.h"
#include "Commands/ManualLowerCommand.h"
#include "Commands/SetLiftPositionCommand.h"
#include <cmath>

OI::OI() {
	controller = new Joystick(CONTROLLER_DEFAULT_PORT);
	intakeToggleButton = new JoystickButton(controller, INTAKE_TOGGLE_BUTTON);
	intakeToggleButton->WhenPressed(new ToggleIntake());
	expelSpinButton = new JoystickButton(controller, EXPEL_BUTTON);
	expelSpinButton->WhileHeld(new ArmMotorExpel());
	intakeSpinButton = new JoystickButton(controller, INTAKE_BUTTON);
	intakeSpinButton->WhileHeld(new ArmMotorIntake());
	liftUpButton = new JoystickButton(controller, LIFT_RAISE_BUTTON);
	liftUpButton->WhileHeld(new ManualRaiseCommand());
	liftDownButton = new JoystickButton(controller, LIFT_LOWER_BUTTON);
	liftDownButton->WhileHeld(new ManualLowerCommand());
	/*boxZeroButton = new JoystickButton(controller, 6);
	boxZeroButton->WhenPressed(new SetLiftPositionCommand(LIFT_ZERO_BOX));
	boxOneButton = new JoystickButton(controller, 7);
	boxOneButton->WhenPressed(new SetLiftPositionCommand(LIFT_ONE_BOX));
	boxTwoButton = new JoystickButton(controller, 8);
	boxTwoButton->WhenPressed(new SetLiftPositionCommand(LIFT_TWO_BOX));
	boxThreeButton = new JoystickButton(controller, 11);
	boxThreeButton->WhenPressed(new SetLiftPositionCommand(LIFT_THREE_BOX));
	boxFourButton = new JoystickButton(controller, 12);
	boxFourButton->WhenPressed(new SetLiftPositionCommand(LIFT_FOUR_BOX));*/

	// Process operator interface input here.
}
float OI::getRightStick(){
	return getStick(controller, RIGHT_VERTICAL);

}
float OI::getLeftStick(){
	return getStick(controller, LEFT_VERTICAL);
}
float OI::getStick(Joystick* stick, int axis){
	float rawInput = stick->GetRawAxis(axis);
	return (rawInput*fabs(rawInput));
}
