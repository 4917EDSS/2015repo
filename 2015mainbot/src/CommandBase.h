#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/LiftSubsystem.h"
#include "Subsystems/drivetrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/StackingSubsystem.h"
#include "OI.h"

//Talons
#define LEFT_DRIVE_1 0
#define LEFT_DRIVE_2 1
#define RIGHT_DRIVE_1 2
#define RIGHT_DRIVE_2 3
#define LIFT_MOTOR_1 7
#define LIFT_MOTOR_2 8
#define ARM_LEFT_MOTOR 4
#define ARM_RIGHT_MOTOR 5

//Air Outputs
#define ARMS_CLOSE 0
#define ARMS_OPEN 1
#define SECONDARY_ARMS_OPEN 0
#define SECONDARY_ARMS_CLOSE 1

//Digital IO
#define TOP_LIMIT_SWITCH 0
#define BOTTOM_LIMIT_SWITCH 1
#define INTAKE_LIMIT_SWITCH 2
#define BOX_HEIGHT_LIMIT_SWITCH 3

//Camera
#define CAMERA_NAME "cam1"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static Drivetrain* m_drivetrain;
	static Intake* m_intake;
	static OI* oi;
	static LiftSubsystem* m_liftSubsystem;
	static StackingSubsystem* m_stackingSubsystem;
};

#endif
