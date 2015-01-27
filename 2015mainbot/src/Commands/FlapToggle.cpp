#include "FlapToggle.h"

FlapToggle::FlapToggle()
{
	Requires (m_stackingSubsystem);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void FlapToggle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FlapToggle::Execute()
{
	if (m_stackingSubsystem->getFlapOpen()) {
		m_stackingSubsystem->setClosed();
	}
	else {
		m_stackingSubsystem->setOpen();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool FlapToggle::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void FlapToggle::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlapToggle::Interrupted()
{

}
