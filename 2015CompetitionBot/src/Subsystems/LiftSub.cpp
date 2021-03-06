#include "LiftSub.h"
#include "../RobotMap.h"
#include "../Commands/MoveMastWithJoystickCmd.h"
#include "../RobotParameters.h"

LiftSub::LiftSub(int liftMotorC, int locks1C, int locks2C, int jaws1C, int jaws2C, int liftEncoder1C, int liftEncoder2C, int topLimitSwitchC, int bottomLimitSwitchC) :
		Subsystem("LiftSub")
{
	liftMotor = new Talon(liftMotorC);
	locks = new DoubleSolenoid(locks1C, locks2C);
	jaws = new DoubleSolenoid(jaws1C, jaws2C);
	liftEncoder = new Encoder(liftEncoder1C, liftEncoder2C);
	onTarget=0;
	destination=0;
	topLimitSwitch = new DigitalInput(topLimitSwitchC);
	bottomLimitSwitch = new DigitalInput(bottomLimitSwitchC);
	oldLiftHeight = 0;
	onTargetCounter = 0;
	stalledCycles = 0;
	cycles = 0;
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
		return LOCKS_OPEN;
	}
	else
	{
		return LOCKS_CLOSED;
	}
}

void LiftSub::ToggleLocks()
{
	if (GetLocks() == LOCKS_OPEN)
	{
		SetLocks(LOCKS_CLOSED);
	}
	else
	{
		SetLocks(LOCKS_OPEN);
	}
}

void LiftSub::ToggleJaws()
{
	if (GetJaws() == JAWS_OPEN && !ArmsAboveJaws())
	{
		SetJaws(JAWS_CLOSED);
	}
	else
	{
		SetJaws(JAWS_OPEN);
		SetLocks(LOCKS_OPEN);
	}
}
void LiftSub::SetJaws(bool isOut)
{
	if (isOut == JAWS_CLOSED && !ArmsAboveJaws())
	{
		jaws->Set(DoubleSolenoid::kReverse);
	}
	else
	{
		jaws->Set(DoubleSolenoid::kForward);
	}
}

bool LiftSub::GetJaws()
{
	if (jaws->Get() == DoubleSolenoid::kForward)
	{
		return JAWS_OPEN;
	}
	else
	{
		return JAWS_CLOSED;
	}
}

int LiftSub::GetArmHeight()
{
	return (int) liftEncoder->GetRaw();
}
void LiftSub::LiftMotorUp(float speed)
{

	SmartDashboard:: PutNumber("Mast Up speed", speed);
	if (GetTopLimitSwitch() && (speed > 0))
	{
		liftMotor->Set(0);
	}
	else if (GetBottomLimitSwitch() && (speed < 0)) {
		liftMotor->Set(0);
		ResetLift();
	}
	else if(GetArmHeight() >= INTERFERENCE_LOCKOUT_EV && GetJaws() == JAWS_CLOSED && speed > 0){
		liftMotor->Set(0);
	}
	else if ((speed < 0) && (GetArmHeight() <= LIFT_ENCODER_SLOWDOWN_DISTANCE)){
		liftMotor->Set(-SLOW_MAST_SPEED);
	}
	else
	{
		liftMotor->Set(speed);
	}
	SmartDashboard:: PutNumber("currentPosition", liftEncoder->GetRaw());
}

void LiftSub::LiftMotorDown(float speed)
{
	if (GetTopLimitSwitch() && (speed < 0))
	{
		liftMotor->Set(0);
	}
	else if (GetBottomLimitSwitch() && (speed > 0)) {
		liftMotor->Set(0);
		ResetLift();
	}
	else if(GetArmHeight() >= INTERFERENCE_LOCKOUT_EV && GetJaws() == JAWS_CLOSED && speed < 0){
			liftMotor->Set(0);
	}
	else if ((speed > 0) && (GetArmHeight() <= SCORE_HEIGHT_EV)){
		liftMotor->Set(-SLOW_MAST_SPEED);
	}
	else
	{
		liftMotor->Set(-speed);
	}
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
	cycles++;
	int currentPosition = liftEncoder->GetRaw();
	if (cycles >= STALL_RECHECK_RATE){
		if (oldLiftHeight == currentPosition)
		{
				stalledCycles++;
		}
		else
		{
			oldLiftHeight = liftEncoder->GetRaw();
			cycles = 0;
		}
	}
	float difference = fabs(currentPosition - destination);
	float speedFactor = difference/LIFT_ENCODER_SLOWDOWN_DISTANCE;
	speedFactor = speedFactor > 1 ? 1.0 : (speedFactor + MIN_SPEED_TO_MOVE_MAST + STALLED_SPEED_BONUS*stalledCycles);
	SmartDashboard:: PutNumber("currentPosition", currentPosition);
	SmartDashboard:: PutNumber("destination", destination);
	if (currentPosition > (destination + LIFT_TOLERANCE))
	{
		LiftMotorDown(speedFactor);
		onTarget = false;
		onTargetCounter = 0;
	}
	else if (currentPosition < (destination - LIFT_TOLERANCE))
	{
		LiftMotorUp(speedFactor);
		onTarget = false;
		onTargetCounter = 0;
	}
	else
	{
		liftMotor->Set(0);
		onTargetCounter++;
		stalledCycles = 0;

		onTarget = true;
	}

}

void LiftSub::ResetLift()
{
	liftEncoder->Reset();
}

bool LiftSub::GetBottomLimitSwitch()
{
	return !bottomLimitSwitch->Get();
}

bool LiftSub::GetTopLimitSwitch()
{
	return false;
}

bool LiftSub::ArmsAboveJaws()
{
	if(GetArmHeight() > INTERFERENCE_LOCKOUT_EV){
		return true;
	}
	else{
		return false;
	}
}
