#include "CameraStartCommand.h"

CameraStartCommand::CameraStartCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void CameraStartCommand::Initialize()
{
	m_cameraSubsystem->StartCapture();
}

// Called repeatedly when this Command is scheduled to run
void CameraStartCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CameraStartCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CameraStartCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraStartCommand::Interrupted()
{

}
