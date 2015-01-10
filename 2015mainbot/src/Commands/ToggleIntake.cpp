#include "ToggleIntake.h"

ToggleIntake::ToggleIntake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleIntake::Initialize() {
	m_intake->SetArms(!m_intake->GetArms());
	
}

// Called repeatedly when this Command is scheduled to run
void ToggleIntake::Execute() {
	
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
