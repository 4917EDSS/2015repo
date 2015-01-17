#include "Intake.h"
#include "../Robotmap.h"
#include "../Commands/ArmMotorIntake.h"

Intake::Intake(int armleft_channel, int armright_channel, int solenoidright_channel, int solenoidleft_channel) : Subsystem("ArmMotor") {
	armRight = new Talon(armright_channel);
	armLeft = new Talon(armleft_channel);
	openClose = new GeneralAirToggle(solenoidright_channel, solenoidleft_channel);
	printf("Left %d \n", solenoidright_channel);
	SetMotor(0);
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
	armLeft->Set(speed);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
