#include "PickUpBoxGrp.h"
#include "IntakeUntilLimitCmd.h"
#include "SetArmsCmd.h"
#include "RobotParameters.h"

PickUpBoxGrp::PickUpBoxGrp()
{
	AddSequential(new IntakeUntilLimitCmd());
	AddSequential(new SETMAST(1));
	AddSequential(new SETLOCK(LOCKS_OPEN));
	AddSequential(new SETMAST(2));
	AddSequential(new SETLOCK(LOCKS_CLOSED));
	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new WaitCommand(MOVEMENT_DELAY));
	AddSequential(new SETMAST(0));

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
}
