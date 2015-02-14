#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
{
private:
	Talon* frontRight;
	Talon* backRight;
	Talon* frontLeft;
	Talon* backLeft;
	Encoder* leftEncoder;
	Encoder* rightEncoder;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DrivetrainSub(int frontrightC, int backrightC, int frontleftC, int backleftC, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C);
	void drive(float leftSpeed, float rightSpeed);
	void InitDefaultCommand();
	void ResetDrive(); //reset both drive encoders
	int GetRawLeftEnc();
	int GetLeftEnc();
	int GetRawRightEnc();
	int GetRightEnc();

};

#endif
