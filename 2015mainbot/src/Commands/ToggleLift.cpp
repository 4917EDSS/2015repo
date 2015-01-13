#include "ToggleLift.h"

ToggleLift::ToggleLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleLift::Initialize() {
	m_liftSubsystem->toggleUpDown();
	
}

// Called repeatedly when this Command is scheduled to run
void ToggleLift::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLift::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleLift::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLift::Interrupted() {
}
