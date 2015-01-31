#ifndef LiftSub_H
#define LiftSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftSub: public Subsystem
{
private:
	bool onTarget;
	int destination;
	Talon* liftMotor;
	DoubleSolenoid* locks;
	Encoder* liftEncoder;
	DigitalInput* resetLimitSwitch;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LiftSub(int liftMotorC, int locks1C, int locks2C, int liftEncoder1C, int liftEncoder2C, int resetLimitSwitchC);
	void InitDefaultCommand();
	void SetLocks(bool isOut);
	bool GetLocks();
	void ToggleLocks();
	int GetArmHeight();
	void LiftMotorUp(float speed);
	void LiftMotorDown(float speed);
	bool IsOnTarget();
	void SetArmsTarget(int target);
	void Update();
	void ResetLift();
	bool GetResetLimitSwitch();
};

#endif
