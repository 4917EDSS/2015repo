#ifndef LIFT_SUBSYSTEM_H
#define LIFT_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class LiftSubsystem: public Subsystem {
private:
	//Solenoid* sensorPower;
	Talon* liftMotor1;
	Talon* liftMotor2;
	DigitalInput* maxHeightLimitSwitch;
	DigitalInput* minHeightLimitSwitch;
	//AnalogInput* boxHeight;
	//DigitalInput* heightSensor;
	//bool onTarget;
	//float liftMotorPosition;
	//int targetCounter;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	//float getLiftHeight();
	//bool isOnTarget();
	//void updateLiftHeight();
	void liftMotorStop();
	void liftMotorUp();
	void liftMotorDown();
	bool isMaxHeight();
	bool isMinHeight();
	//void setLiftHeight(float liftHeight);
	//void toggleUpDown();
	LiftSubsystem(int lift_channel1, int lift_channel2, int top_limit_channel, int bottom_limit_channel);
	//void InitDefaultCommand();
};

#endif
