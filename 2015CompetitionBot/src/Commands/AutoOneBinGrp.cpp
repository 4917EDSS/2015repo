#include "AutoOneBinGrp.h"
#include "RobotParameters.h"
#include "DriveStraightCmd.h"
#include "SetArmsCmd.h"
#include "SetJawsCmd.h"
#include "SetLocksCmd.h"

/*
 * Place the robot on beside the bin with the arms towards the bin on the side opposite the auto zone
 */

AutoOneBinGrp::AutoOneBinGrp()
{
	AddSequential(new SetArmsCmd(ARMS_OPEN));
	AddSequential(new SetJawsCmd(JAWS_OPEN));
	AddSequential(new SetLocksCmd(LOCKS_OPEN));
	AddSequential(new DriveStraightCmd(DRIVE_CENTER_TO_CENTER, MAX_SPEED_EV/2));

}
