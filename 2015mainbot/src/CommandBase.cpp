#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
Intake* CommandBase::m_intake = NULL;
Drivetrain* CommandBase::m_drivetrain = NULL;
OI* CommandBase::oi = NULL;
LiftSubsystem* CommandBase::m_liftSubsystem = NULL;
StackingSubsystem* CommandBase::m_stackingSubsystem = NULL;

void CommandBase::init() {
        // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	m_intake = new Intake(ARM_LEFT_MOTOR, ARM_RIGHT_MOTOR, ARMS_CLOSE, ARMS_OPEN, INTAKE_LIMIT_SWITCH);
	m_drivetrain = new Drivetrain(LEFT_DRIVE_1, LEFT_DRIVE_2, RIGHT_DRIVE_1,  RIGHT_DRIVE_2);
	oi = new OI();
	m_liftSubsystem = new LiftSubsystem(LIFT_MOTOR_1, LIFT_MOTOR_2, TOP_LIMIT_SWITCH, BOTTOM_LIMIT_SWITCH);
	m_stackingSubsystem = new StackingSubsystem(FLAP_OPEN, FLAP_CLOSE, BOX_HEIGHT_LIMIT_SWITCH);
	m_stackingSubsystem->setClosed();
}
