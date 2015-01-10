#include "ArmMotorExpel.h"
#include <math.h>

ArmMotorExpel::ArmMotorExpel() {
	Requires(m_intake);
}

// Called just before this Command runs the first time
void ArmMotorExpel::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ArmMotorExpel::Execute() {
	m_intake->SetMotor(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMotorExpel::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmMotorExpel::End() {
	m_intake->SetMotor(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMotorExpel::Interrupted() {
	m_intake->SetMotor(0.0);
}
