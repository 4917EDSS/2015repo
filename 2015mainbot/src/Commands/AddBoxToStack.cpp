#include "AddBoxToStack.h"

AddBoxToStack::AddBoxToStack()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (m_intake);
	Requires (m_liftSubsystem);
	Requires (m_stackingSubsystem);
}

// Called just before this Command runs the first time
void AddBoxToStack::Initialize()
{
	m_stackingSubsystem->setOpen();
	m_liftSubsystem->liftMotorUp();
}

// Called repeatedly when this Command is scheduled to run
void AddBoxToStack::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AddBoxToStack::IsFinished()
{
	return m_stackingSubsystem->isPressed();
}

// Called once after isFinished returns true
void AddBoxToStack::End()
{
	m_liftSubsystem->liftMotorStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AddBoxToStack::Interrupted()
{
	m_liftSubsystem->liftMotorStop();
}
