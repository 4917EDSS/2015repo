#include "IntakeSub.h"
#include "../RobotMap.h"
#include "Commands/SpinIntakeWithJoystickCmd.h"

IntakeSub::IntakeSub(int armRightC, int armLeftC, int armsOpenClose1C, int armsOpenClose2C, int intakeLimitC) :
		Subsystem("IntakeSub")
{
	armRight = new Talon(armRightC);
	armLeft = new Talon(armLeftC);
	armsOpenClose = new DoubleSolenoid(armsOpenClose1C, armsOpenClose2C);
	intakeLimit = new DigitalInput(intakeLimitC);
}

void IntakeSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new SpinIntakeWithJoystickCmd());
}
void IntakeSub::SetBeltsIn(float speed)
{
	armRight->Set(-speed);
	armLeft->Set(speed);
}
void IntakeSub::SetBeltsOut(float speed)
{
	armRight->Set(speed);
	armLeft->Set(-speed);
}
void IntakeSub::SetBeltsLeft(float speed)
{
	armRight->Set(-speed);
	armLeft->Set(-speed);
}
void IntakeSub::SetBeltsRight(float speed)
{
	armRight->Set(speed);
	armLeft->Set(speed);
}
void IntakeSub::SetArms(bool armsOut)
{
	if(armsOut) {
		armsOpenClose->Set(DoubleSolenoid::kForward);
	}
	else {
		armsOpenClose->Set(DoubleSolenoid::kReverse);
	}
}
bool IntakeSub::GetArms()
{
	if(armsOpenClose->Get()==DoubleSolenoid::kForward){
		return true;
	}
	else{
		return false;
	}
}
bool IntakeSub::IsLimitHit()
{
	return intakeLimit->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
