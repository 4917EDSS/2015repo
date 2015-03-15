#ifndef DriveStraightCmd_H
#define DriveStraightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStraightCmd: public CommandBase
{
private:
	int targetDistance;
	float targetSpeed;
	float currentSpeed;
	int state;
	bool finished;
	int previousLeftEncoder;
	int previousRightEncoder;
	int counter;

public:
	DriveStraightCmd(int driveDistanceMillimeters, float driveSpeedParam);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
