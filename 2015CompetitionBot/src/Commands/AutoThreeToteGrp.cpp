#include "AutoThreeToteGrp.h"
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

AutoThreeToteGrp::AutoThreeToteGrp()
{
	//POSITION REQUIRED: From the driver station perspective, the robot has its arms around but not touching the rightmost yellow tote.
	AddSequential(new SetLocksCmd(LOCKS_OPEN));
	AddSequential(new SetJawsCmd(JAWS_CLOSED));
		AddSequential(new ResetLiftEncoderCmd());
		AddSequential(new SetLocksCmd(LOCKS_OPEN));
		AddSequential(new SetArmsCmd(ARMS_CLOSED));
		AddSequential(new SetJawsCmd(JAWS_CLOSED));
		AddSequential(new IntakeUntilLimitCmd());
	AddParallel(new DriveStraightCmd(DISTANCE_BETWEEN_TOTES, MAX_SPEED_EV/2));
		AddSequential(new SetLiftHeightCmd(TRANSFER_EV));
		AddSequential(new SetLocksCmd(LOCKS_CLOSED));
		AddSequential(new WaitCommand(LOCKS_CLOSE_DELAY));
		AddSequential(new SetArmsCmd(ARMS_OPEN));
		AddSequential(new WaitCommand(ARMS_OPEN_DELAY));
		AddSequential(new ResetLiftEncoderCmd());

		AddSequential(new SetArmsCmd(ARMS_CLOSED));
		AddSequential(new SetJawsCmd(JAWS_CLOSED));
		AddSequential(new IntakeUntilLimitCmd());
	AddParallel(new DriveStraightCmd(DISTANCE_BETWEEN_TOTES, MAX_SPEED_EV/2));
		AddSequential(new GrabStackGrp());
		AddSequential(new SetLiftHeightCmd(TRANSFER_EV));
		AddSequential(new SetLocksCmd(LOCKS_CLOSED));
		AddSequential(new WaitCommand(LOCKS_CLOSE_DELAY));
		AddSequential(new SetArmsCmd(ARMS_OPEN));
		AddSequential(new WaitCommand(ARMS_OPEN_DELAY));
		AddSequential(new ResetLiftEncoderCmd());

	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new IntakeUntilLimitCmd());
	AddParallel(new SetLiftHeightCmd(FIRST_CONTACT_EV));
	AddSequential(new DriveTurnCmd(90, true, MAX_SPEED_EV/2));
	AddSequential(new DriveStraightCmd(DRIVE_CENTER_TO_CENTER, MAX_SPEED_EV/2));
	AddSequential(new AutoDropStackGrp());
	AddSequential(new DriveStraightCmd(BACK_OFF_DISTANCE, MAX_SPEED_EV/2));
}
