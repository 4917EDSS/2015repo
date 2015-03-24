#include "DriveStraightCmd.h"
#include "RobotParameters.h"

// driveDistanceMillimeters - Negative means drive in reverse
// driveSpeedParam - Speed in mm/s?  Negative changes the sign of the distance parameter
DriveStraightCmd::DriveStraightCmd(int driveDistanceMillimeters, float driveSpeedParam)
{
	targetDistance = driveDistanceMillimeters;
	if( driveSpeedParam < 0 )
	{
		// Negative speed so change movement direction
		targetDistance *= -1;
	}
	targetSpeed = fabs(driveSpeedParam);
	currentSpeed = 0;
	state = 0;			// Always start at beginning of state-machine
	finished = false;

	backward = targetDistance < 0;

////////////
	previousRightEncoder = 0;
	previousLeftEncoder = 0;
	counter = 0;
////////////

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(rDrivetrainSub);
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize()
{
	// Command state machine:
	//
	// [State 0]
	// Purpose:		Set initial conditions.  Immediately goes to state 1.
	//
	// [State 1]
	// Purpose:		Soft speed ramp-up to minimize slip and to have both motors accelerate at an equal rate (i.e. drive straight)
	// Control:		P controller on speed with periodic set-point increase (i.e. increase target speed every Execute)
	// To State 2:	- when close to target speed
	// To State 3:	- when close to target distance
	//
	// [State 2]
	// Purpose:		Have both motors maintain the same speed (i.e. drive straight)
	// Control:		PD controller on speed with constant set-point
	// To State 3:	- when close to the target distance
	//
	// [State 3]
	// Purpose:		Soft speed ramp-down to avoid slip and distance overshoot
	// Control:		PID controller on distance using original distance set-point
	// To State 4:	- when within tolerance of desired distance
	//
	// [State 4]
	// Purpose:		Done.

	state = 0;
	finished = false;
	rDrivetrainSub->ResetDrive();
    rDrivetrainSub->SetSpeedPIDMode(SPEED_MODE_AUTO);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{
	if (backward) {
		switch(state)
		{
		// State 0:  Initial setup
		case 0:
			// Manage the speed PID
			rDrivetrainSub->PIDDrive(-SOFT_START_ACCEL_VALUE);
			rDrivetrainSub->EnableSpeedPID();
			currentSpeed = SOFT_START_ACCEL_VALUE;

			state = 1;
			break;

		// State 1:  Acceleration
		case 1:
			if(fabs(targetDistance - rDrivetrainSub->GetLeftEnc()) < (DECEL_DISTANCE(currentSpeed)) )
			{
				// We've gotten to the close to the target distance before getting to target speed
				state = 2;
			}
			else if( (currentSpeed / targetSpeed) > SOFT_START_SPEED_CUTOFF_RATIO )
			{
				// At target speed.  Hold this speed.
				rDrivetrainSub->PIDDrive(-targetSpeed);
				state = 2;
			}
			else
			{
				// We haven't reached target speed yet so keep accelerating
				currentSpeed += SOFT_START_ACCEL_VALUE;
				rDrivetrainSub->PIDDrive(-currentSpeed);
			}
			break;

		// State 2:  Constant speed
		case 2:
			if( fabs(targetDistance - rDrivetrainSub->GetLeftEnc()) < (DECEL_DISTANCE(targetSpeed)) )
			{
				// We've gotten to the close to the target distance.  Start the distance PID to decelerate.
				rDrivetrainSub->PIDDist(targetDistance, -currentSpeed);
				rDrivetrainSub->DisableSpeedPID();
				rDrivetrainSub->EnableDistancePID();
				state = 3;
			}

			break;

		// State 3:  Deceleration to target distance
		case 3:
			// if we are within distance-PID tolerance, stop
			if( rDrivetrainSub->isOnDistTarget()) {
				state = 4;
			}
			break;

		// State 4:  Stop
		case 4:
		default:
			// other cleanup?
			finished = true;
			break;
		}
	}
	else{
		switch(state)
		{
		// State 0:  Initial setup
		case 0:
			// Manage the speed PID
			rDrivetrainSub->PIDDrive(SOFT_START_ACCEL_VALUE);
			rDrivetrainSub->EnableSpeedPID();
			currentSpeed = SOFT_START_ACCEL_VALUE;

			state = 1;
			break;

		// State 1:  Acceleration
		case 1:
			if(targetDistance - rDrivetrainSub->GetLeftEnc() < (DECEL_DISTANCE(currentSpeed)) )
			{
				// We've gotten to the close to the target distance before getting to target speed
				state = 2;
			}
			else if( (currentSpeed / targetSpeed) > SOFT_START_SPEED_CUTOFF_RATIO )
			{
				// At target speed.  Hold this speed.
				rDrivetrainSub->PIDDrive(targetSpeed);
				state = 2;
			}
			else
			{
				// We haven't reached target speed yet so keep accelerating
				currentSpeed += SOFT_START_ACCEL_VALUE;
				rDrivetrainSub->PIDDrive(currentSpeed);
			}
			break;

		// State 2:  Constant speed
		case 2:
			if(targetDistance - rDrivetrainSub->GetLeftEnc() < (DECEL_DISTANCE(targetSpeed)))
			{
				// We've gotten to the close to the target distance.  Start the distance PID to decelerate.
				rDrivetrainSub->PIDDist(targetDistance, currentSpeed);
				rDrivetrainSub->DisableSpeedPID();
				rDrivetrainSub->EnableDistancePID();
				state = 3;
			}

			break;

		// State 3:  Deceleration to target distance
		case 3:
			// if we are within distance-PID tolerance, stop
			if( rDrivetrainSub->isOnDistTarget()) {
				state = 4;
			}
			break;

		// State 4:  Stop
		case 4:
		default:
			// other cleanup?
			finished = true;
			break;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	return finished;
}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{
	rDrivetrainSub->DisableDistancePID();
	rDrivetrainSub->DisableTurnPID();
	rDrivetrainSub->DisableSpeedPID();
	rDrivetrainSub->Drive(0,0);

	rDrivetrainSub->SetSpeedPIDMode(SPEED_MODE_NORMAL);
	state = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{
	End();
}
