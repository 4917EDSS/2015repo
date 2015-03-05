#include "QuickStackGrp.h"
#include "SetArmsCmd.h"
#include "SetJawsCmd.h"
#include "SetLiftHeightCmd.h"
#include "RobotParameters.h"

QuickStackGrp::QuickStackGrp()
{
	AddSequential(new SetJawsCmd(JAWS_OPEN));
	AddSequential(new SetLiftHeightCmd(TWO_STACK_EV));
	AddSequential(new SetArmsCmd(ARMS_OPEN));
	AddSequential(new WaitCommand(ARMS_OPEN_DELAY));
	AddSequential(new SetLiftHeightCmd(ONE_STACK_EV));
	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new WaitCommand(ARMS_CLOSE_DELAY));
	AddSequential(new SetLiftHeightCmd(TOTE_CHUTE_INTAKE_EV));
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

	//open arms and go to correct height just above first box
	//close arms and raise to 2 stack hieght
}
