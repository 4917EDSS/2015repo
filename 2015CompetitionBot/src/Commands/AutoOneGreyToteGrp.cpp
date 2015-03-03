#include "AutoOneGreyToteGrp.h"
#include "RobotParameters.h"
#include "ResetLiftEncoderCmd.h"
#include "DriveStraightCmd.h"
#include "PickUpBoxCmd.h"
#include "IntakeUntilLimitCmd.h"

AutoOneGreyToteGrp::AutoOneGreyToteGrp()
{
	AddSequential (new ResetLiftEncoderCmd());
	AddSequential (new SetLocksCmd(LOCKS_OPEN));
	AddParallel (new IntakeUntilLimitCmd());
	AddSequential (new DriveStraightCmd(DRIVE_INTO_LANDFILL_DISTANCE));
	AddSequential (new PickUpBoxCmd());
	AddSequential (new DriveStraightCmd(LANDFILL_TO_AUTO_ZONE_DISTANCE));


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
