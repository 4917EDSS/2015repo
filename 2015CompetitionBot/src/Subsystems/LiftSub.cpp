#include "LiftSub.h"
#include "../RobotMap.h"
#include "../Commands/MoveMastWithJoystickCmd.h"
#include "../RobotParameters.h"

LiftSub::LiftSub(int liftMotorC, int locks1C, int locks2C, int liftEncoder1C, int liftEncoder2C, int resetLimitSwitchC) :
		Subsystem("LiftSub")
{
	liftMotor = new Talon(liftMotorC);
	locks = new DoubleSolenoid(locks1C, locks2C);
	liftEncoder = new Encoder(liftEncoder1C, liftEncoder2C);
	onTarget=0;
	destination=0;
	resetLimitSwitch = new DigitalInput(resetLimitSwitchC);
	onTargetCounter = 0;
}

void LiftSub::InitDefaultCommand()
{
	SetDefaultCommand(new MoveMastWithJoystickCmd());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LiftSub::SetLocks(bool isOut)
{
	if (isOut == LOCKS_OPEN)
	{
		locks->Set(DoubleSolenoid::kForward);
	}
	else
	{
		locks->Set(DoubleSolenoid::kReverse);
	}
}

bool LiftSub::GetLocks()
{
	if (locks->Get() == DoubleSolenoid::kForward)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LiftSub::ToggleLocks()
{
	if (locks->Get() == DoubleSolenoid::kForward)
	{
		locks->Set(DoubleSolenoid::kReverse);
	}
	else
	{
		locks->Set(DoubleSolenoid::kForward);
	}
}

int LiftSub::GetArmHeight()
{
	return (int) liftEncoder->GetRaw();
}

void LiftSub::LiftMotorUp(float speed)
{
	liftMotor->Set(speed);
	SmartDashboard:: PutNumber("currentPosition", liftEncoder->GetRaw());
}

void LiftSub::LiftMotorDown(float speed)
{
	liftMotor->Set(-speed);
	SmartDashboard:: PutNumber("currentPosition", liftEncoder->GetRaw());
}

bool LiftSub::IsOnTarget()
{
	return onTarget;
}

void LiftSub::SetArmsTarget(int target)
{
	destination = target;
}

void LiftSub::Update()
{
	int currentPosition = liftEncoder->GetRaw();
	SmartDashboard:: PutNumber("currentPosition", currentPosition);
	SmartDashboard:: PutNumber("destination",destination );
	if (currentPosition > (destination + LIFT_TOLERANCE))
	{
		LiftMotorDown(1);
		onTarget = false;
		onTargetCounter = 0;
	}
	else if (currentPosition < (destination - LIFT_TOLERANCE))
	{
		LiftMotorUp(1);
		onTarget = false;
		onTargetCounter = 0;
	}
	else
	{
		liftMotor->Set(0);
		onTargetCounter++;
		if(onTargetCounter > 500)
		{
			onTarget = true;
			onTargetCounter = 0;
		}
	}

}

void LiftSub::ResetLift()
{
	liftEncoder->Reset();
}

bool LiftSub::GetResetLimitSwitch()
{
	return resetLimitSwitch->Get();
}
