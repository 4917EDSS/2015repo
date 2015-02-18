#include "DriveTurnCmd.h"
#include "RobotParameters.h"

DriveTurnCmd::DriveTurnCmd(int turnDegrees, bool isClockwiseTurnParam, float driveSpeedParam)
{
	driveSpeed = fabs(driveSpeedParam);
	isClockwiseTurn = isClockwiseTurnParam;
	turnEncoderValues = turnDegrees * DEGREE_ROTATE_TO_ENCODER_FACTOR;
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveTurnCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
	rDrivetrainSub->EnablePID();
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
void DriveTurnCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished()
{
	/*if (isClockwiseTurn)
	{
		if (rDrivetrainSub->GetRawLeftEnc() > turnEncoderValues && rDrivetrainSub->GetRawRightEnc() < -turnEncoderValues)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (rDrivetrainSub->GetRawLeftEnc() < -turnEncoderValues && rDrivetrainSub->GetRawRightEnc() > turnEncoderValues)
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/
	return rDrivetrainSub->isLeftOnTarget() && rDrivetrainSub->isRightOnTarget();

}

// Called once after isFinished returns true
void DriveTurnCmd::End()
{
	rDrivetrainSub->Drive(0, 0);
	rDrivetrainSub->DisablePID();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurnCmd::Interrupted()
{
	End();
}
