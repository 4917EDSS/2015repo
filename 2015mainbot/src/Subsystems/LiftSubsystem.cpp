#include "RobotParameters.h"
#include "LiftSubsystem.h"
#include "../Robotmap.h"

LiftSubsystem::LiftSubsystem(int lift_channel1, int lift_channel2, int lift_talon_channel, int encoder_channel) : Subsystem("LiftSubsystem") {
	lifterArticulationRight = new Solenoid(lift_channel1);
	lifterArticulationLeft = new Solenoid(lift_channel2);
	sensorPower = new Solenoid(7);
	heightSensor = new DigitalInput(9);
	isUp = false;
	liftMotorPosition = 0;
	targetCounter = 0;
	onTarget = false;
	liftMotor = new Talon(lift_talon_channel);
	boxHeight = new AnalogInput(encoder_channel);
}
    
void LiftSubsystem::InitDefaultCommand() {
	
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


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

void LiftSubsystem::liftMotorUp(){
	liftMotor->Set(-1);
}

void LiftSubsystem::liftMotorDown(){
	liftMotor->Set(1);
}

void LiftSubsystem::setLiftHeight(float liftHeight){
	liftMotorPosition = liftHeight;
}

void LiftSubsystem::liftMotorStop(){
	liftMotor->Set(0);
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
