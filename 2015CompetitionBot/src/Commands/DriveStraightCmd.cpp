#include "DriveStraightCmd.h"
#include "RobotParameters.h"

DriveStraightCmd::DriveStraightCmd(int driveDistanceMillimeters, float driveSpeedParam)
{
	leftSpeed = driveSpeedParam;
	rightSpeed = leftSpeed;
	forward = driveDistanceMillimeters > 0;
	targetDistance = driveDistanceMillimeters;
	currentDrive = 0;
	previousRightEncoder = 0;
	previousLeftEncoder = 0;
	Requires(rDrivetrainSub);
	counter = 0;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize()
{
	/*rDrivetrainSub->ResetDrive();
	rDrivetrainSub->Drive(leftSpeed, rightSpeed);*/
	rDrivetrainSub->ResetDrive();
	rDrivetrainSub->EnableDistancePID();
	rDrivetrainSub->EnableTurnPID();
	rDrivetrainSub->SetRightSetpoint(targetDistance, rightSpeed);
	rDrivetrainSub->SetLeftSetpoint(targetDistance, leftSpeed);

}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	/*
	counter++;
	if (counter>5000){

		if (rDrivetrainSub->GetRightEnc() == previousRightEncoder
				&& rDrivetrainSub->GetLeftEnc() == previousLeftEncoder) {
			return true;
		}

		previousLeftEncoder = rDrivetrainSub->GetLeftEnc();
		previousRightEncoder = rDrivetrainSub->GetRightEnc();

		counter = 0;
	}*/
	return rDrivetrainSub->isLeftOnTarget() && rDrivetrainSub->isRightOnTarget();
}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{
	rDrivetrainSub->DisableDistancePID();
	rDrivetrainSub->DisableTurnPID();
	rDrivetrainSub->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{
	End();
}
