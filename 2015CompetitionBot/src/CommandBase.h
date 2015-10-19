#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/DrivetrainSub.h"
#include "Subsystems/IntakeSub.h"
#include "Subsystems/LiftSub.h"
//#include "Subsystems/CameraSub.h"

//Talons
#define LeftDrivePWM 1
#define RightDrivePWM 3
#define LiftMotorPWM 4
#define ArmLeftMotorPWM 7
#define ArmRightMotorPWM 8

//Air Outputs
#define ArmsSolenoid1PNC 0
#define ArmsSolenoid2PNC 1
#define LockSolenoid1PNC 2
#define LockSolenoid2PNC 3
#define JawsSolenoid1PNC 4
#define JawsSolenoid2PNC 5
#define ContainerJaw1PNC 6
#define ContainerJaw2PNC 7

//Digital IO
#define LeftDriveEncoder1DIO 4
#define LeftDriveEncoder2DIO 5
#define RightDriveEncoder1DIO 6
#define RightDriveEncoder2DIO 7
#define LiftEncoder1DIO 8
#define LiftEncoder2DIO 9
#define TopLimitSwitchDIO 0
#define BottomLimitSwitchDIO 1
#define IntakeLimitSwitchDIO 2
#define BoxHeightLimitSwitchDIO 3


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DrivetrainSub *rDrivetrainSub;
	static IntakeSub *rIntakeSub;
	static LiftSub *rLiftSub;
	static OI *oi;
	//static CameraSub *rCameraSub;
};

#endif
