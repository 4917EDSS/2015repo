#include "DriveUntilButtonPressedCommand.h"

DriveUntilButtonPressedCommand::DriveUntilButtonPressedCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	drivingForward = true;
	Requires(m_inputButton);
	Requires(m_drivetrain);
}

// Called just before this Command runs the first time
void DriveUntilButtonPressedCommand::Initialize() {
	m_drivetrain->drive(1,1);
	drivingForward = true;
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilButtonPressedCommand::Execute() {
	if (m_inputButton->IsPressed()){
		if (drivingForward){
			m_drivetrain->drive(-1.0,-1.0);
			drivingForward = false;
		}
	}
	else{
		if (!drivingForward){
			m_drivetrain->drive(1.0,1.0);
			drivingForward = true;
		}
	}
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilButtonPressedCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveUntilButtonPressedCommand::End() {
	drivingForward = false;
	m_drivetrain->drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilButtonPressedCommand::Interrupted() {
	drivingForward = false;
	m_drivetrain->drive(0,0);
}
