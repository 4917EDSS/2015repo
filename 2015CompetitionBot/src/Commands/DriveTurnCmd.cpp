#include "DriveTurnCmd.h"
#include "RobotParameters.h"

DriveTurnCmd::DriveTurnCmd(int turnDegrees, bool isClockwiseTurnParam, float driveSpeedParam)
{
	driveSpeed = fabs(driveSpeedParam);
	isClockwiseTurn = isClockwiseTurnParam;
	turnEncoderValues = turnDegrees * DISTANCE_PER_DEGREE;
	previousRightEncoder = 0;
	previousLeftEncoder = 0;
	Requires(rDrivetrainSub);
	counter = 0;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveTurnCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
	rDrivetrainSub->EnableDistancePID();
	if (isClockwiseTurn)
	{
//		rDrivetrainSub->Drive(driveSpeed, -driveSpeed);
		rDrivetrainSub->SetRightSetpoint(-turnEncoderValues, driveSpeed);
		rDrivetrainSub->SetLeftSetpoint(turnEncoderValues, driveSpeed);
	}
	else
	{
//		rDrivetrainSub->Drive(-driveSpeed, driveSpeed);
		rDrivetrainSub->SetRightSetpoint(turnEncoderValues, driveSpeed);
		rDrivetrainSub->SetLeftSetpoint(-turnEncoderValues, driveSpeed);
	}
}

// Called repeatedly when this Command is scheduled to run
// Called repeatedly when this Command is scheduled to run
void DriveTurnCmd::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished()
 {
	counter++;
	if (counter>50){

		if (rDrivetrainSub->GetRightEnc() == previousRightEncoder
				&& rDrivetrainSub->GetLeftEnc() == previousLeftEncoder) {
			return true;
		}

		previousLeftEncoder = rDrivetrainSub->GetLeftEnc();
		previousRightEncoder = rDrivetrainSub->GetRightEnc();

		counter = 0;
	}
	return false;
}

// Called once after isFinished returns true
void DriveTurnCmd::End()
{
	rDrivetrainSub->Drive(0, 0);
	rDrivetrainSub->DisableDistancePID();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurnCmd::Interrupted()
{
	End();
}
