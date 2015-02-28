#include "AutoThreeToteOneBinGrp.h"
#include "RobotParameters.h"
#include "PickUpBoxGrp.h"
#include "DriveStraightCmd.h"
#include "IntakeUntilLimitCmd.h"
#include "DriveTurnCmd.h"
#include "AutoDropStackGrp.h"

AutoThreeToteOneBinGrp::AutoThreeToteOneBinGrp()
{
	AddSequential(new PickUpBoxGrp());

}
