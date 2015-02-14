#include "PickUpBoxCmd.h"
#include "PickUpBoxGrp.h"
#include "PickUpFirstBoxGrp.h"
#include "RobotParameters.h"

PickUpBoxCmd::PickUpBoxCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void PickUpBoxCmd::Initialize()
{
	CommandGroup* grp;
	if (rLiftSub->GetLocks()==LOCKS_CLOSED){
		grp = new PickUpBoxGrp();
	}
	else{
		grp = new PickUpFirstBoxGrp();
	}
	grp->Start();
}

// Called repeatedly when this Command is scheduled to run
void PickUpBoxCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PickUpBoxCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PickUpBoxCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PickUpBoxCmd::Interrupted()
{

}
