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
	bool isUp;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	void toggleUpDown();
	LiftSubsystem(int lift_channel1, int lift_channel2);
	void InitDefaultCommand();
};

#endif
