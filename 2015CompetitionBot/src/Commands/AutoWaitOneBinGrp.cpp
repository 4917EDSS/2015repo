#include <Commands/AutoWaitOneBinGrp.h>
#include "RobotParameters.h"
#include "DriveStraightCmd.h"
#include "DriveTurnCmd.h"
#include "SetLiftHeightCmd.h"
#include "SetArmsCmd.h"
#include "SetJawsCmd.h"
#include "SetLocksCmd.h"
#include "StartIntakeCmd.h"
#include "StopBeltsCmd.h"
#include "GrabStackGrp.h"
#include "ResetLiftEncoderCmd.h"
#include "IntakeUntilLimitCmd.h"


AutoWaitOneBinGrp::AutoWaitOneBinGrp()
{

	AddSequential(new WaitCommand(5.5));
	AddSequential(new SetLocksCmd(LOCKS_OPEN));
	AddSequential(new SetJawsCmd(JAWS_OPEN));
	AddSequential(new SetJawsCmd(ARMS_OPEN));
	AddSequential(new DriveStraightCmd(700, MAX_SPEED_EV/2));
	AddSequential(new SetArmsCmd(ARMS_CLOSED));
	AddSequential(new StartIntakeCmd());
	AddSequential(new WaitCommand(1.5));
	AddSequential(new StopBeltsCmd());
	AddSequential(new SetLiftHeightCmd(2500));
	AddSequential(new DriveStraightCmd(BACKUP_WITH_GREEN_EV, MAX_SPEED_EV/2));
}
