#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include <Components/DriveTurnController.h>
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Components/Encoder4917.h"
#include "../Components/DoublePIDController.h"
#include "../Components/DrivetrainRotationMeasure.h"
#include "../Components/DriveTurnController.h"

class DrivetrainSub: public Subsystem
{
private:
	Talon* rightMotor;
	Talon* leftMotor;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	Encoder4917* leftEncoderSpeed;
	PIDController* rightController;
	Encoder4917* rightEncoderSpeed;
	PIDController* leftController;
	DoublePIDController* leftDoubleController;
	DoublePIDController* rightDoubleController;
	DrivetrainRotationMeasure* rotationMeasure;
	DriveTurnController* turnOutput;
	PIDController* turnController;

	int controlState;
	float lastSpeed;
	float rightTurnModifier;
	float leftTurnModifier;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DrivetrainSub(int rightMotorC, int leftMotorC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C);
	void Drive(float leftSpeed, float rightSpeed);
	void PIDDrive(float leftSpeed, float rightSpeed);
	void SetP(float p);
	float GetP();
	void SetI(float i);
	float GetI();
	void InitDefaultCommand();
	void ResetDrive(); //reset both drive encoders
	int GetRawLeftEnc();
	int GetLeftEnc();
	int GetRawRightEnc();
	int GetRightEnc();
	void ToggleControls();
	int GetControls();
	void EnableDistancePID();
	void DisableDistancePID();
	void EnableSpeedPID();
	void DisableSpeedPID();
	void DisableTurnPID();
	void EnableTurnPID();
	void SetLeftSetpoint(int setpoint, float speed);
	void SetRightSetpoint(int setpoint, float speed);
	bool isLeftOnTarget();
	bool isRightOnTarget();
	double GetLeftEncoderRate();
	double GetRightEncoderRate();
	void SetTurnModifier(float turnModifier);

};

#endif
