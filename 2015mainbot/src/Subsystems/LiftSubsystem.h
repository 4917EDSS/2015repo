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
	DigitalInput* maxHeightLimitSwitch;
	DigitalInput* minHeightLimitSwitch;
	Encoder* encoder;

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
	void liftMotorSet(float speed);
	bool isMaxHeight();
	bool isMinHeight();
	//void setLiftHeight(float liftHeight);
	//void toggleUpDown();
	LiftSubsystem(int lift_channel1, int top_limit_channel, int bottom_limit_channel, int encoderForward_channel, int encoderReverse_channel);
	void InitDefaultCommand();
};

#endif
