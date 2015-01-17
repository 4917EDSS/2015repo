#include "ToggleIntake.h"

ToggleIntake::ToggleIntake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(m_intake);
}

// Called just before this Command runs the first time
void ToggleIntake::Initialize() {
	

}

// Called repeatedly when this Command is scheduled to run
void ToggleIntake::Execute() {
	m_intake->ToggleArms();
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleIntake::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleIntake::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleIntake::Interrupted() {
}
