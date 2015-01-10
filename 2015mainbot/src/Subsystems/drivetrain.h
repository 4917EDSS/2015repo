#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * 
 * 
 * 
 */
class Drivetrain: public Subsystem {
private:
	Talon* frontright;
	Talon* middleright;
	Talon* backright;
	Talon* frontleft;
	Talon* middleleft;
	Talon* backleft;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Drivetrain(int frontright_channel, int middleright_channel, int backright_channel, int frontleft_channel, int middleleft_channel, int backleft_channel);
	void drive(float rightspeed, float leftspeed);
	void InitDefaultCommand();
};
#endif
