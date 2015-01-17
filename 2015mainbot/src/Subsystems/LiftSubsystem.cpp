#include "RobotParameters.h"
#include "LiftSubsystem.h"
#include "../Robotmap.h"

LiftSubsystem::LiftSubsystem(int lift_channel1, int lift_channel2,  int top_limit_channel, int bottom_limit_channel) : Subsystem("LiftSubsystem") {
	liftMotor1 = new Talon(lift_channel1);
	liftMotor2 = new Talon(lift_channel2);
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

//void LiftSubsystem::InitDefaultCommand() {
	
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
//}



void LiftSubsystem::liftMotorUp(){
	liftMotor1->Set(-1);
	liftMotor2->Set(-1);
}

void LiftSubsystem::liftMotorDown(){
	liftMotor1->Set(1);
	liftMotor2->Set(1);
}

void LiftSubsystem::liftMotorStop(){
	liftMotor1->Set(0);
	liftMotor2->Set(0);
}
/*
// Put methods for controlling this subsystem
// here. Call these from Commands.
void LiftSubsystem::toggleUpDown(){
	isUp = !isUp;
	lifterArticulationRight->Set(isUp);
	lifterArticulationLeft->Set(!isUp);
}

float LiftSubsystem::getLiftHeight(){
	return boxHeight->GetAverageVoltage();
}


void LiftSubsystem::setLiftHeight(float liftHeight){
	liftMotorPosition = liftHeight;
}

void LiftSubsystem::updateLiftHeight(){
	if(getLiftHeight() > liftMotorPosition + LIFT_TOLERANCE){
		liftMotorDown();
	}
	else if(getLiftHeight() < liftMotorPosition - LIFT_TOLERANCE){
		liftMotorUp();
	}
	else{
		liftMotorStop();
	}
	printf("currentHeight: %f\n desiredHeight: %f\n isOnTarget: %d\n", getLiftHeight(), liftMotorPosition, isOnTarget());
	printf("heightSensor: %d\n", heightSensor->Get());
}

bool LiftSubsystem::isOnTarget(){
	if(getLiftHeight() < liftMotorPosition + LIFT_TOLERANCE &&
			getLiftHeight() > liftMotorPosition - LIFT_TOLERANCE){
		targetCounter++;
	}
	else{
		targetCounter = 0;
	}
	return targetCounter > 20;
}
*/
