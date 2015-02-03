#include "IntakeUntilLimitCmd.h"

IntakeUntilLimitCmd::IntakeUntilLimitCmd()
{
	Requires (rIntakeSub);
	if (rIntakeSub==NULL) {
		printf("\n\n\n\n\n:(\n\n\n\n");
	}
	else {
		printf("\n\n\n\n\n:)\n\n\n\n");
	}
}

// Called just before this Command runs the first time
void IntakeUntilLimitCmd::Initialize()
{
	rIntakeSub->SetBeltsIn(1.0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeUntilLimitCmd::Execute()
{
	//printf("Button command");
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeUntilLimitCmd::IsFinished()
{
	return rIntakeSub->IsLimitHit();
}

// Called once after isFinished returns true
void IntakeUntilLimitCmd::End()
{
	rIntakeSub->SetBeltsIn(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeUntilLimitCmd::Interrupted()
{
	printf("intakeuntilcmd interrupt \n");
}
