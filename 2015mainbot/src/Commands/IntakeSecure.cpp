#include "IntakeSecure.h"

IntakeSecure::IntakeSecure()
{
	Requires (m_intake);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void IntakeSecure::Initialize()
{
	m_intake->SetMotor(-1.0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeSecure::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeSecure::IsFinished()
{
	return m_intake->IsTouched();
}

// Called once after isFinished returns true
void IntakeSecure::End()
{
	m_intake->SetMotor(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeSecure::Interrupted()
{
	m_intake->SetMotor(0.0);
}
