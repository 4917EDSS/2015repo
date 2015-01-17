#include "ManualRaiseCommand.h"

ManualRaiseCommand::ManualRaiseCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ManualRaiseCommand::Initialize() {
	if (m_liftSubsystem->isMaxHeight()){
		m_liftSubsystem->liftMotorUp();
	}
}

// Called repeatedly when this Command is scheduled to run
void ManualRaiseCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ManualRaiseCommand::IsFinished() {
	return !m_liftSubsystem->isMaxHeight();
}

// Called once after isFinished returns true
void ManualRaiseCommand::End() {
	m_liftSubsystem->liftMotorStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualRaiseCommand::Interrupted() {
	m_liftSubsystem->liftMotorStop();
}
