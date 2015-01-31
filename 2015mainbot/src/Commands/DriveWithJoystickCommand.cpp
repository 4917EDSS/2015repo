#include "DriveWithJoystickCommand.h"
#include <math.h>

DriveWithJoystickCommand::DriveWithJoystickCommand() {
	Requires(m_drivetrain);
}

// Called just before this Command runs the first time
void DriveWithJoystickCommand::Initialize() {
	
}

// Dual Joystick Code
// Called repeatedly when this Command is scheduled to run
void DriveWithJoystickCommand::Execute() {
	m_drivetrain->drive(oi->DGetRightVer(), oi->DGetLeftVer());
}

// PLAYSTATION Controller Code
// Called repeatedly when this Command is scheduled to run


// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystickCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystickCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystickCommand::Interrupted() {
}
