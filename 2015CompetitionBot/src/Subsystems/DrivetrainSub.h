#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
{
private:
	Talon* rightMotor;
	Talon* leftMotor;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	PIDController* rightController;
	PIDController* leftController;
	int controlState;
	float lastSpeed;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DrivetrainSub(int rightMotorC, int leftMotorC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C);
	void Drive(float leftSpeed, float rightSpeed);
	void InitDefaultCommand();
	void ResetDrive(); //reset both drive encoders
	int GetRawLeftEnc();
	int GetLeftEnc();
	int GetRawRightEnc();
	int GetRightEnc();
	void ToggleControls();
	int GetControls();
	void EnablePID();
	void DisablePID();
	void SetLeftSetpoint(int setpoint, float speed);
	void SetRightSetpoint(int setpoint, float speed);
	bool isLeftOnTarget();
	bool isRightOnTarget();

};

#endif
