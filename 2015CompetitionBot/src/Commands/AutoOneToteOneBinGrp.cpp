#include <Commands/AutoOneToteOneBinGrp.h>
#include "RobotParameters.h"
#include "DriveStraightCmd.h"
#include "DriveTurnCmd.h"
#include "SetLiftHeightCmd.h"
#include "SetArmsCmd.h"
#include "SetJawsCmd.h"
#include "SetLocksCmd.h"
#include "GrabStackGrp.h"

/*
 * Place robot beside green bin on the opposite side of the tote arms facing the bin
 */

AutoOneToteOneBinGrp::AutoOneToteOneBinGrp()
{
	AddParallel(new SetArmsCmd(ARMS_OPEN));
	AddParallel(new SetLocksCmd(LOCKS_OPEN));
	AddSequential(new SetJawsCmd(JAWS_OPEN));
	AddSequential(new DriveStraightCmd(DRIVE_ONE_GREEN_BIN, .5));
	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new WaitCommand(ARMS_CLOSE_DELAY));
	AddSequential(new SetLiftHeightCmd(TWO_STACK_EV));
	AddSequential(new DriveStraightCmd(DRIVE_ONE_GREEN_BIN, .5));
	AddSequential(new SetArmsCmd(ARMS_OPEN));
	AddSequential(new WaitCommand(ARMS_OPEN_DELAY));
	AddSequential(new SetLiftHeightCmd(BOTTOM_LIMIT_EV));
	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new WaitCommand(ARMS_CLOSE_DELAY));
	AddSequential(new SetLiftHeightCmd(SCORE_HEIGHT_EV));
	AddSequential(new DriveTurnCmd(90, false, .5));
	AddSequential(new DriveStraightCmd(DRIVE_CENTER_TO_CENTER, .5));
	AddSequential(new SetLiftHeightCmd(BOTTOM_LIMIT_EV));
	AddSequential(new SetArmsCmd(ARMS_OPEN));
}
