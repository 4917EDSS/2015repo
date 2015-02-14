#include "PickUpFirstBoxGrp.h"
#include "IntakeUntilLimitCmd.h"
#include "SetArmsCmd.h"
#include "RobotParameters.h"
#include "SetLocksCmd.h"
#include "SetJawsCmd.h"
#include "SetLiftHeightCmd.h"
#include "GrabStackGrp.h"
#include "ResetLiftEncoderCmd.h"

PickUpFirstBoxGrp::PickUpFirstBoxGrp()
{
	AddParallel(new ResetLiftEncoderCmd());
	AddSequential(new SetLocksCmd(LOCKS_OPEN));
	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new SetJawsCmd(JAWS_CLOSED));
	AddSequential(new IntakeUntilLimitCmd());
	AddSequential(new SetLiftHeightCmd(TRANSFER_EV));
	AddSequential(new SetLocksCmd(LOCKS_CLOSED));
	AddSequential(new WaitCommand(LOCKS_CLOSE_DELAY));
	AddSequential(new SetArmsCmd(ARMS_OPEN));
	AddSequential(new WaitCommand(ARMS_OPEN_DELAY));
	AddSequential(new SetLiftHeightCmd(BOTTOM_LIMIT_EV));

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
