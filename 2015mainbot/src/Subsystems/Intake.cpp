#include "Intake.h"
#include "../Robotmap.h"
#include "../Commands/ArmMotorIntake.h"

Intake::Intake(int armleft_channel, int armright_channel, int solenoidright_channel, int solenoidleft_channel) : Subsystem("ArmMotor") {
	armRight = new Talon(armright_channel);
	armLeft = new Talon(armleft_channel);
	armArticulationRight = new Solenoid(solenoidright_channel);
	armArticulationLeft = new Solenoid(solenoidleft_channel);
	SetMotor(0);
}

    
void Intake::SetArms(bool isout) {
	armArticulationRight->Set(isout);
	armArticulationLeft->Set(!isout);
}
bool Intake::GetArms() {
	return armArticulationRight->Get();
}

void Intake::SetMotor(float speed) {
	armRight->Set(speed);
	armLeft->Set(speed);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
