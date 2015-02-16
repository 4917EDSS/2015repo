#ifndef DriveStraightCmd_H
#define DriveStraightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStraightCmd: public CommandBase
{
private:
	int currentDrive;
	int targetDistance;
	float rightSpeed;
	float leftSpeed;
	bool forward;

public:
	DriveStraightCmd(int driveDistanceMillimeters, float driveSpeedParam);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
