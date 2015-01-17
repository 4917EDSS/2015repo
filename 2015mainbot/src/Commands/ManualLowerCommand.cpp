#include "ManualLowerCommand.h"

ManualLowerCommand::ManualLowerCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ManualLowerCommand::Initialize() {
	if (m_liftSubsystem->isMinHeight()){
		m_liftSubsystem->liftMotorDown();
	}
}

// Called repeatedly when this Command is scheduled to run
void ManualLowerCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ManualLowerCommand::IsFinished() {
	return !m_liftSubsystem->isMinHeight();
}

// Called once after isFinished returns true
void ManualLowerCommand::End() {
	m_liftSubsystem->liftMotorStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualLowerCommand::Interrupted() {
	m_liftSubsystem->liftMotorStop();
}
