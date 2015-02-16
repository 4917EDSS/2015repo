#include "AutoOneBinGrp.h"
#include "RobotParameters.h"
#include "DriveStraightCmd.h"

/*
 * Place the robot on beside the bin with the arms towards the bin on the side opposite the auto zone
 */

AutoOneBinGrp::AutoOneBinGrp()
{
	AddSequential(new DriveStraightCmd(DRIVE_CENTER_TO_CENTER, .5));

}
