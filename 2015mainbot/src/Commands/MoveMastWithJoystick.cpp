#include "MoveMastWithJoystick.h"

MoveMastWithJoystick::MoveMastWithJoystick()
{
	Requires(m_liftSubsystem);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void MoveMastWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveMastWithJoystick::Execute()
{
	m_liftSubsystem->liftMotorSet(oi->OGetRightVer());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveMastWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveMastWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveMastWithJoystick::Interrupted()
{
	m_liftSubsystem->liftMotorSet(0.0);

}
