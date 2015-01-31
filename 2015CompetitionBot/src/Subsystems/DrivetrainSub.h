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

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DrivetrainSub(int frontrightC, int backrightC, int frontleftC, int backleftC);
	void drive(float leftSpeed, float rightSpeed);
	void InitDefaultCommand();
};

#endif
