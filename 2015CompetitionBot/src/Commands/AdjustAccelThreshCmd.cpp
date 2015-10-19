#include "AdjustAccelThreshCmd.h"

AdjustAccelThreshCmd::AdjustAccelThreshCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AdjustAccelThreshCmd::Initialize()
{

	rDrivetrainSub->SetAccelThresh(SmartDashboard::GetNumber("Accel thresh")/1000);
}

// Called repeatedly when this Command is scheduled to run
void AdjustAccelThreshCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AdjustAccelThreshCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AdjustAccelThreshCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AdjustAccelThreshCmd::Interrupted()
{

}
