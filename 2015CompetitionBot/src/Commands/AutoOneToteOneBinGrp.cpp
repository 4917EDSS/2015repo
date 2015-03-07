#include <Commands/AutoOneToteOneBinGrp.h>
#include "RobotParameters.h"
#include "DriveStraightCmd.h"
#include "DriveTurnCmd.h"
#include "SetLiftHeightCmd.h"
#include "SetArmsCmd.h"
#include "SetJawsCmd.h"
#include "SetLocksCmd.h"
#include "GrabStackGrp.h"
#include "ResetLiftEncoderCmd.h"
#include "IntakeUntilLimitCmd.h"

/*
 * Place robot around green bin on the opposite side of the tote arms facing the bin with jaws and locks open.
 */

AutoOneToteOneBinGrp::AutoOneToteOneBinGrp()
{
	AddParallel(new SetLocksCmd(LOCKS_OPEN));
	AddSequential(new SetJawsCmd(JAWS_OPEN));
	AddSequential(new SetJawsCmd(ARMS_OPEN));
	AddSequential(new SetLiftHeightCmd(GREEN_BIN_ABOVE_TOTE_EV));
	AddSequential(new DriveStraightCmd(DRIVE_ONE_GREEN_BIN, MAX_SPEED_EV/2));
	AddSequential(new ResetLiftEncoderCmd());
	AddParallel(new IntakeUntilLimitCmd());
	AddParallel(new DriveTurnCmd(90, false, MAX_SPEED_EV/2));
	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new WaitCommand(ARMS_CLOSE_DELAY));
	AddSequential(new SetLiftHeightCmd(SCORE_HEIGHT_EV));
	AddSequential(new SetJawsCmd(JAWS_CLOSED));
	AddSequential(new SetLocksCmd(LOCKS_CLOSED));
	AddSequential(new DriveStraightCmd(DRIVE_CENTER_TO_CENTER, MAX_SPEED_EV/2));
	AddSequential(new SetJawsCmd(JAWS_OPEN));
	AddSequential(new SetLocksCmd(LOCKS_OPEN));
	AddSequential(new ResetLiftEncoderCmd());
	AddParallel(new SetArmsCmd(ARMS_OPEN));
}
