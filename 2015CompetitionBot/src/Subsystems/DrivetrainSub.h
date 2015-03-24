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
#define NORMAL_SPEED_CTRL_ID	0
#define AUTO_SPEED_CTRL_ID		1
#define DISTANCE_CTRL_ID		2
#define TURN_CTRL_ID			3	// Not currently used

// Speed PID modes
#define SPEED_MODE_AUTO 0
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
	PIDController* leftDriveSpeedController;
	PIDController* rightDriveSpeedController;
	PIDController* leftAutoSpeedController;
	PIDController* rightAutoSpeedController;
	PIDController* leftCurSpeedController;		// Pointers to current speed controllers
	PIDController* rightCurSpeedController;
	PIDController* leftDistanceController;
	PIDController* rightDistanceController;
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
	void PIDDist(float distance, float speed);
	void SetExternallyAccessiblePid(int id);
	int GetExternallyAccessiblePid();
	void SetP(float p);
	float GetP();
	void SetD(float d);
	float GetD();
	void SetI(float i);
	float GetI();
	void SetF(float f);
	float GetF();
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
	bool isOnDistTarget();
	bool isLeftOnTarget();
	bool isRightOnTarget();
	double GetLeftEncoderRate();
	double GetRightEncoderRate();
	void SetTurnModifier(float turnModifier);

};

#endif
