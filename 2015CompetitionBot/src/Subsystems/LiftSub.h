#ifndef LiftSub_H
#define LiftSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftSub: public Subsystem
{
private:
	bool onTarget;
	int destination;
	int onTargetCounter;
	Talon* liftMotor;
	DoubleSolenoid* locks;
	DoubleSolenoid* jaws;
	Encoder* liftEncoder;
	DigitalInput* topLimitSwitch;
	DigitalInput* bottomLimitSwitch;
	bool ArmsAboveJaws();
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LiftSub(int liftMotorC, int locks1C, int locks2C, int jaws1C, int jaws2C, int liftEncoder1C, int liftEncoder2C, int topLimitSwitchC, int bottomLimitSwitchC);
	void InitDefaultCommand();
	void SetLocks(bool isOut);
	bool GetLocks();
	void ToggleLocks();
	void SetJaws(bool isOut);
	bool GetJaws();
	void ToggleJaws();
	int GetArmHeight();
	void LiftMotorUp(float speed);
	void LiftMotorDown(float speed);
	bool IsOnTarget();
	void SetArmsTarget(int target);
	void Update();
	void ResetLift();
	bool GetBottomLimitSwitch();
	bool GetTopLimitSwitch();
};

#endif
