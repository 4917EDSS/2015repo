#include "SetLiftPositionCommand.h"

SetLiftPositionCommand::SetLiftPositionCommand(float position) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	desiredPosition = position;
}

// Called just before this Command runs the first time
void SetLiftPositionCommand::Initialize() {
	m_liftSubsystem->setLiftHeight(desiredPosition);
	printf("setCommand: %f\n", desiredPosition);
}

// Called repeatedly when this Command is scheduled to run
void SetLiftPositionCommand::Execute() {
	m_liftSubsystem->updateLiftHeight();
}

// Make this return true when this Command no longer needs to run execute()
bool SetLiftPositionCommand::IsFinished() {
	return m_liftSubsystem->isOnTarget();
}

// Called once after isFinished returns true
void SetLiftPositionCommand::End() {
	m_liftSubsystem->liftMotorStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLiftPositionCommand::Interrupted() {
	End();
}
