#include <Commands/Turn90CCWiseDropGrp.h>
#include "RobotParameters.h"
#include "DriveTurnCmd.h"
#include "DriveStraightCmd.h"
#include "ResetLiftEncoderCmd.h"
#include "SetArmsCmd.h"
#include "SetJawsCmd.h"

Turn90CCWiseDropGrp::Turn90CCWiseDropGrp()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	//AddSequential(new DriveTurnCmd(90, false, MAX_SPEED_EV/2));
	AddSequential(new DriveStraightCmd(DRIVE_CENTER_TO_CENTER, MAX_SPEED_EV/2));
	AddSequential(new ResetLiftEncoderCmd());
	AddSequential(new SetArmsCmd(ARMS_OPEN));
	AddSequential(new SetJawsCmd(JAWS_OPEN));
	AddSequential(new DriveStraightCmd(BACK_OFF_DISTANCE, MAX_SPEED_EV));
}
