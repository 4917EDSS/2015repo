#include "SpinIntakeWithJoystick.h"
#include "RobotParameters.h"

SpinIntakeWithJoystick::SpinIntakeWithJoystick()
{
	Requires(m_intake);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SpinIntakeWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SpinIntakeWithJoystick::Execute()
{
	if (fabs(oi->getRightOperatorHorizontalStick())>CONTROLLER_HOR_INTAKE_TOLERANCE)
	{
		m_intake->RotateBox(oi->getRightOperatorHorizontalStick());
	}
	else
	{
		m_intake->SetMotor(oi->getLeftOperatorStick());
	}

}

// Make this return true when this Command no longer needs to run execute()
bool SpinIntakeWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SpinIntakeWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinIntakeWithJoystick::Interrupted()
{
	m_intake->SetMotor(0.0);
}
