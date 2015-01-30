#include "RobotParameters.h"
#include "LiftSubsystem.h"
#include "../Commands/MoveMastWithJoystick.h"
#include "../Robotmap.h"

LiftSubsystem::LiftSubsystem(int lift_channel1, int top_limit_channel, int bottom_limit_channel) : Subsystem("LiftSubsystem") {
	liftMotor1 = new Talon(lift_channel1);
	maxHeightLimitSwitch = new DigitalInput(top_limit_channel);
	minHeightLimitSwitch = new DigitalInput(bottom_limit_channel);
//	sensorPower = new Solenoid(7);
//	heightSensor = new DigitalInput(9);
//	isUp = false;
//	liftMotorPosition = 0;
///	targetCounter = 0;
//	onTarget = false;
//	liftMotor = new Talon(lift_talon_channel);
//	boxHeight = new AnalogInput(encoder_channel);
}
    
bool LiftSubsystem::isMaxHeight(){
	return maxHeightLimitSwitch->Get();
}

bool LiftSubsystem::isMinHeight(){
	return minHeightLimitSwitch->Get();
}

void LiftSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new MoveMastWithJoystick());
}



void LiftSubsystem::liftMotorUp(){
	liftMotor1->Set(-1.0);
}

void LiftSubsystem::liftMotorDown(){
	liftMotor1->Set(1.0);
}

void LiftSubsystem::liftMotorStop(){
	liftMotor1->Set(0.0);
}
void LiftSubsystem::liftMotorSet(float speed){
	liftMotor1->Set(speed);
}
