#include "AdjustPIDCmd.h"

AdjustPIDCmd::AdjustPIDCmd()
{

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AdjustPIDCmd::Initialize()
{
	rDrivetrainSub->SetP(SmartDashboard::GetNumber("p value")/1000);
	rDrivetrainSub->SetI(SmartDashboard::GetNumber("i value")/1000);
	rDrivetrainSub->SetD(SmartDashboard::GetNumber("d value")/1000);

}

// Called repeatedly when this Command is scheduled to run
void AdjustPIDCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AdjustPIDCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AdjustPIDCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AdjustPIDCmd::Interrupted()
{

}
