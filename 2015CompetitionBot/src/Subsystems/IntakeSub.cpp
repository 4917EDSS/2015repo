#include "IntakeSub.h"
#include "../RobotMap.h"
#include "Commands/SpinIntakeWithJoystickCmd.h"
#include "RobotParameters.h"

IntakeSub::IntakeSub(int armRightC, int armLeftC, int armsOpenClose1C, int armsOpenClose2C, int conJawOpenClose1C, 
		int conJawOpenClose2C, int intakeLimitC) :
		Subsystem("IntakeSub")
{
	armRight = new Talon(armRightC);
	armLeft = new Talon(armLeftC);
	armsOpenClose = new DoubleSolenoid(armsOpenClose1C, armsOpenClose2C);
	conJawOpenClose = new DoubleSolenoid(conJawOpenClose1C, conJawOpenClose2C);
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
	if (IsLimitHit() && speed > 0 && CommandBase::rLiftSub->GetArmHeight() < SCORE_HEIGHT_EV)
	{
		speed = 0;
	}
	SetBelts(-speed, speed);

}
void IntakeSub::SetBeltsOut(float speed)
{
	SetBelts(-speed, speed);
}
void IntakeSub::SetBeltsLeft(float speed)
{
	SetBelts(speed, speed);
}
void IntakeSub::SetBeltsRight(float speed)
{
	SetBelts(-speed, -speed);
}
void IntakeSub::SetBelts(float leftSpeed, float rightSpeed )
{

	armRight->Set(rightSpeed);
	armLeft->Set(leftSpeed);
}
void IntakeSub::SetArms(bool armsOut)
{
	if(armsOut == ARMS_OPEN) {
		armsOpenClose->Set(DoubleSolenoid::kForward);
	}
	else {
		armsOpenClose->Set(DoubleSolenoid::kReverse);
	}
}
bool IntakeSub::GetArms()
{
	if(armsOpenClose->Get()==DoubleSolenoid::kForward){
		return ARMS_OPEN;
	}
	else{
		return ARMS_CLOSED;
	}
}
void IntakeSub::ToggleArms()
{
	SetArms(!GetArms());
}
void IntakeSub::SetConJaw(bool conJawOut)
{
	if(conJawOut == CONJAW_OPEN) {
			conJawOpenClose->Set(DoubleSolenoid::kForward);
	}
		else {
			conJawOpenClose->Set(DoubleSolenoid::kReverse);
		}
}
bool IntakeSub::GetConJaw()
{
	if(conJawOpenClose->Get()==DoubleSolenoid::kForward){
			return CONJAW_OPEN;
		}
		else{
			return CONJAW_CLOSED;
		}
}
void IntakeSub::ToggleConJaw()
{
	SetConJaw(!GetConJaw());
}
bool IntakeSub::IsLimitHit()
{
	return !intakeLimit->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
