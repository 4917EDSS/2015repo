/*#include "LiftHoldResetCommand.h"

LiftHoldResetCommand::LiftHoldResetCommand() {
	// Use Requires() here to declare subsystem dependencies
	Requires(m_liftSubsystem);
}
//checkTopLimitSwitch()

// Called just before this Command runs the first time
void LiftHoldResetCommand::Initialize() {
	m_liftSubsystem->setMotor(1.0);
}

// Called repeatedly when this Command is scheduled to run
void LiftHoldResetCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool LiftHoldResetCommand::IsFinished() {
	if (checkTopLimitSwitch()){
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void LiftHoldResetCommand::End() {
	m_liftSubsystem->setMotor(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftHoldResetCommand::Interrupted() {
	m_liftSubsystem->setMotor(0.0);
}*/
