#include "AutoOneBinGrp.h"
#include "RobotParameters.h"
#include "DriveStraightCmd.h"
#include "SetArmsCmd.h"
#include "SetJawsCmd.h"
#include "SetLocksCmd.h"
#include "ResetLiftEncoderCmd.h"
#include "SetLiftHeightCmd.h"

/*
 * Place the robot beside the bin with the arms towards the bin on the auto zone side. Arms should be just under the handles.
 */

AutoOneBinGrp::AutoOneBinGrp()
{
	//AddSequential(new WaitCommand(4));
	AddSequential(new SetJawsCmd(JAWS_OPEN));
	AddSequential(new SetLocksCmd(LOCKS_OPEN));
	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new WaitCommand(ARMS_CLOSE_DELAY));
	AddSequential(new SetLiftHeightCmd(GREEN_BIN_ABOVE_TOTE_EV));
	//AddSequential(new DriveStraightCmd(-STAGING_TO_AUTO_DISTANCE, MAX_SPEED_EV/2));
}
