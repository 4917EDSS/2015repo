#ifndef IntakeSub_H
#define IntakeSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSub: public Subsystem
{
private:

	Talon* armRight;
	Talon* armLeft;

	DoubleSolenoid* armsOpenClose;

	DigitalInput* intakeLimit;



	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	IntakeSub(int armRightC, int armLeftC, int armsOpenClose1C, int armsOpenClose2C, int intakeLimitC);
	void InitDefaultCommand();
	void SetBeltsIn(float speed);
	void SetBeltsOut(float speed);
	void SetBeltsRight(float speed);
	void SetBeltsLeft(float speed);
	void SetBelts(float leftSpeed, float rightSpeed);
	void SetArms(bool armsOut);
	bool GetArms();
	void ToggleArms();
	bool IsLimitHit();

};

#endif
