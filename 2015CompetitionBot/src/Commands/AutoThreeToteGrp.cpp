#include "AutoThreeToteGrp.h"
#include "RobotParameters.h"
#include "PickUpBoxGrp.h"
#include "DriveStraightCmd.h"
#include "IntakeUntilLimitCmd.h"
#include "DriveTurnCmd.h"
#include "AutoDropStackGrp.h"

AutoThreeToteGrp::AutoThreeToteGrp()
{
	//POSITION REQUIRED: From the driver station perspective, the robot has its arms around but not touching the rightmost yellow tote.
	AddSequential(new PickUpBoxGrp());
	AddSequential(new DriveStraightCmd(DISTANCE_BETWEEN_TOTES, 0.5));
	AddSequential(new PickUpBoxGrp());
	AddSequential(new DriveStraightCmd(DISTANCE_BETWEEN_TOTES, 0.5));
	AddSequential(new IntakeUntilLimitCmd());
	AddSequential(new DriveTurnCmd(90, true, 0.5));
	AddSequential(new DriveStraightCmd(STAGING_TO_AUTO_DISTANCE, 0.5));
	AddSequential(new AutoDropStackGrp());
	AddSequential(new DriveStraightCmd(BACK_OFF_DISTANCE, 0.5));
}
