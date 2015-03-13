#include "AutoClotheslineBinGrp.h"
#include "RobotParameters.h"
#include "DriveStraightCmd.h"

AutoClotheslineBinGrp::AutoClotheslineBinGrp()
{
	AddSequential(new DriveStraightCmd(-CLOTHESLINE_DROP_POSITION, MAX_SPEED_EV));
	AddSequential(new WaitCommand(CLOTHESLINE_CLOSE_DELAY));
	AddSequential(new DriveStraightCmd(PULL_BIN_OFF_STEP, MAX_SPEED_EV));
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
