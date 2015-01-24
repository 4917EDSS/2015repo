#include "BoxHandoff.h"

BoxHandoff::BoxHandoff()
{
	Requires (m_stackingSubsystem);
	Requires (m_intake);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BoxHandoff::Initialize()
{
	m_stackingSubsystem->setClosed();
}

// Called repeatedly when this Command is scheduled to run
void BoxHandoff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool BoxHandoff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void BoxHandoff::End()
{
	m_intake->SetArms(true);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BoxHandoff::Interrupted()
{
	m_intake->SetArms(true);
}
