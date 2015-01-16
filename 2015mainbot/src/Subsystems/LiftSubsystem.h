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
	Solenoid* lifterArticulationRight;
	Solenoid* lifterArticulationLeft;
	Solenoid* sensorPower;
	Talon* liftMotor;
	AnalogInput* boxHeight;
	DigitalInput* heightSensor;
	bool isUp;
	bool onTarget;
	float liftMotorPosition;
	int targetCounter;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	float getLiftHeight();
	bool isOnTarget();
	void updateLiftHeight();
	void liftMotorStop();
	void liftMotorUp();
	void liftMotorDown();
	void setLiftHeight(float liftHeight);
	void toggleUpDown();
	LiftSubsystem(int lift_channel1, int lift_channel2, int lift_talon_channel, int encoder_channel);
	void InitDefaultCommand();
};

#endif
