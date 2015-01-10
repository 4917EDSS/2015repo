#include "ArmMotorIntake.h"
#include <math.h>

ArmMotorIntake::ArmMotorIntake() {
	Requires(m_intake);
}

// Called just before this Command runs the first time
void ArmMotorIntake::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ArmMotorIntake::Execute() {
	m_intake->SetMotor(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMotorIntake::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmMotorIntake::End() {
	m_intake->SetMotor(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMotorIntake::Interrupted() {
	m_intake->SetMotor(0.0);
}
