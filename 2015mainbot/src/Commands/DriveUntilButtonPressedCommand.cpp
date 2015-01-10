#include "DriveUntilButtonPressedCommand.h"

DriveUntilButtonPressedCommand::DriveUntilButtonPressedCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveUntilButtonPressedCommand::Initialize() {
	m_drivetrain->drive(1,1);
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilButtonPressedCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilButtonPressedCommand::IsFinished() {
	return inputbutton->IsPressed();
}

// Called once after isFinished returns true
void DriveUntilButtonPressedCommand::End() {
	m_drivetrain->drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilButtonPressedCommand::Interrupted() {
}
