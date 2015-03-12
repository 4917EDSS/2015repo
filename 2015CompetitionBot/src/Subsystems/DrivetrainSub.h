#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include <Components/DriveTurnController.h>
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Components/Encoder4917.h"
#include "../Components/DoublePIDController.h"
#include "../Components/DrivetrainRotationMeasure.h"
#include "../Components/DriveTurnController.h"

// PID Controller IDs
// For use with GetP/I/D and SetP/I/D routing
#define SPEED_CTRL_ID	0
#define DRIVE_CTRL_ID	1
#define TURN_CTRL_ID	2

// Speed PID modes
#define SPEED_MODE_SOFT_START 0
#define SPEED_MODE_NORMAL 1


class DrivetrainSub: public Subsystem
{
private:
	Talon* rightMotor;
	Talon* leftMotor;
	Encoder* leftDistanceEncoder;
	Encoder* rightDistanceEncoder;
	Encoder4917* leftSpeedVirtualEncoder;
	Encoder4917* rightSpeedVirtualEncoder;
	PIDController* rightSpeedController;
	PIDController* leftSpeedController;
	DrivetrainRotationMeasure* rotationMeasure;
	DriveTurnController* turnOutput;
	PIDController* turnController;

	int controlState;
	int pidGetSetId;	// which PID controller GetP/I/D and SetP/I/D are connected to

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DrivetrainSub(int rightMotorC, int leftMotorC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C);
	void Drive(float leftSpeed, float rightSpeed);
	void PIDDrive(float speed);
	void PIDDrive(float leftSpeed, float rightSpeed);
	void SetExternallyAccessiblePid(int id);
	void SetP(float p);
	float GetP();
	void SetD(float d);
	float GetD();
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
	void SetSpeedPIDMode(int mode);
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
