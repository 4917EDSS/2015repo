#include "Intake.h"
#include "../Robotmap.h"
#include "../Commands/SpinIntakeWithJoystick.h"
#include "../Commands/ManualLowerCommand.h"

Intake::Intake(int armleft_channel, int armright_channel, int solenoidright_channel, int solenoidleft_channel, int limitswitch_channel) :Subsystem("ArmMotor") {
	armRight = new Talon(armright_channel);
	armLeft = new Talon(armleft_channel);
	openClose = new GeneralAirToggle(solenoidright_channel, solenoidleft_channel);
	intakeLimit = new DigitalInput(limitswitch_channel);
	SetMotor(0);
}
void Intake::InitDefaultCommand(){
	SetDefaultCommand(new SpinIntakeWithJoystick());
}
void Intake::SetArms(bool isout) {
	openClose->set(isout);

}
void Intake::ToggleArms() {
	openClose->toggle();

}
bool Intake::GetArms() {
	return openClose->get();
}

void Intake::SetMotor(float speed) {
	armRight->Set(speed);
	armLeft->Set(-speed);
}
bool Intake::IsTouched() {
	return !intakeLimit->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
