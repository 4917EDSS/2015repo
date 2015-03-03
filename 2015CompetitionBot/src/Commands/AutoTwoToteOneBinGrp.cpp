#include <Commands/Turn90CCWiseDropGrp.h>
#include "AutoTwoToteOneBinGrp.h"
#include "RobotParameters.h"
#include "PickUpBoxGrp.h"
#include "DriveStraightCmd.h"
#include "IntakeUntilLimitCmd.h"
#include "DriveTurnCmd.h"
#include "AutoDropStackGrp.h"
#include "SetLiftHeightCmd.h"
#include "SetArmsCmd.h"
#include "SetLocksCmd.h"
#include "SetJawsCmd.h"
#include "PickUpFirstBoxGrp.h"
#include "ResetLiftEncoderCmd.h"
#include "GrabStackGrp.h"


AutoTwoToteOneBinGrp::AutoTwoToteOneBinGrp()
{

	AddParallel(new SetLocksCmd(LOCKS_OPEN));
		AddSequential(new SetJawsCmd(JAWS_OPEN));
		AddSequential(new SetArmsCmd(ARMS_OPEN));
		AddSequential(new SetLiftHeightCmd(GREEN_BIN_ABOVE_TOTE_EV));
		AddSequential(new DriveStraightCmd(DRIVE_ONE_GREEN_BIN, MAX_SPEED_EV));
		AddSequential(new ResetLiftEncoderCmd());
		AddSequential(new SetArmsCmd(ARMS_CLOSED));
		AddSequential(new IntakeUntilLimitCmd());
		AddParallel(new DriveStraightCmd(DISTANCE_BETWEEN_TOTES, MAX_SPEED_EV/2));
		AddSequential(new SetLiftHeightCmd(TRANSFER_EV));
		AddSequential(new SetJawsCmd(JAWS_CLOSED));
		AddSequential(new WaitCommand(JAWS_CLOSE_DELAY));
		AddSequential(new SetLocksCmd(LOCKS_CLOSED));
		AddSequential(new SetArmsCmd(ARMS_OPEN));
		AddSequential(new WaitCommand(ARMS_OPEN_DELAY));
		AddSequential(new ResetLiftEncoderCmd());
		AddSequential(new SetArmsCmd(ARMS_CLOSED));
		AddSequential(new IntakeUntilLimitCmd());
		AddParallel(new GrabStackGrp());
		AddSequential(new Turn90CCWiseDropGrp());


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
