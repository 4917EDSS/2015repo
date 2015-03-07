#include <Commands/Turn90CCWiseDropGrp.h>
#include "AutoThreeToteOneBinGrp.h"
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

AutoThreeToteOneBinGrp::AutoThreeToteOneBinGrp()
{
	//POSITION REQUIRED: From the driver station perspective, the robot has its arms around but not touching the handles of the leftmost green bin.
		AddParallel(new SetLocksCmd(LOCKS_OPEN));
		AddSequential(new SetJawsCmd(JAWS_OPEN));
		AddSequential(new SetJawsCmd(ARMS_OPEN));
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
		AddParallel(new DriveStraightCmd(DISTANCE_BETWEEN_TOTES, MAX_SPEED_EV/2));
	AddSequential(new GrabStackGrp());
	AddParallel(new DriveTurnCmd(90, false, MAX_SPEED_EV/2));
	AddSequential(new SetLiftHeightCmd(TRANSFER_EV));
	AddSequential(new SetLocksCmd(LOCKS_CLOSED));
	AddSequential(new WaitCommand(LOCKS_CLOSE_DELAY));
	AddSequential(new SetArmsCmd(ARMS_OPEN));
	AddSequential(new WaitCommand(ARMS_OPEN_DELAY));
	AddSequential(new ResetLiftEncoderCmd());

	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new IntakeUntilLimitCmd());
	AddSequential(new GrabStackGrp());
	AddSequential(new Turn90CCWiseDropGrp());

}
