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
	Talon* lifterMotor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	void setMotor(float motorSpeed);
	LiftSubsystem(int lift_channel);
	void InitDefaultCommand();
};

#endif
