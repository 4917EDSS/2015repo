#include "AutoThreeToteGrp.h"
#include "RobotParameters.h"
#include "PickUpBoxGrp.h"
#include "DriveStraightCmd.h"
#include "IntakeUntilLimitCmd.h"
#include "DriveTurnCmd.h"
#include "AutoDropStackGrp.h"
#include "SetLiftHeightCmd.h"

AutoThreeToteGrp::AutoThreeToteGrp()
{
	//POSITION REQUIRED: From the driver station perspective, the robot has its arms around but not touching the rightmost yellow tote.
	AddSequential(new PickUpBoxGrp());
	AddSequential(new DriveStraightCmd(DISTANCE_BETWEEN_TOTES, MAX_SPEED_EV/2));
	AddSequential(new PickUpBoxGrp());
	AddSequential(new DriveStraightCmd(DISTANCE_BETWEEN_TOTES, MAX_SPEED_EV/2));
	AddSequential(new IntakeUntilLimitCmd());
	AddParallel(new SetLiftHeightCmd(SCORE_HEIGHT_EV));
	AddSequential(new DriveTurnCmd(90, true, 0.5));
	AddSequential(new DriveStraightCmd(STAGING_TO_AUTO_DISTANCE, MAX_SPEED_EV/2));
	AddSequential(new AutoDropStackGrp());
	AddSequential(new DriveStraightCmd(BACK_OFF_DISTANCE, MAX_SPEED_EV/2));
}
