#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
Intake* CommandBase::m_intake = NULL;
Drivetrain* CommandBase::m_drivetrain = NULL;
InputButton* CommandBase::m_inputButton = NULL;
OI* CommandBase::oi = NULL;
LiftSubsystem* CommandBase::m_liftSubsystem = NULL;

void CommandBase::init() {
        // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	m_intake = new Intake(7,8,1,2);
	m_drivetrain = new Drivetrain(1, 3, 5, 2, 4, 6);
	m_inputButton = new InputButton(1);
	oi = new OI();
	m_liftSubsystem = new LiftSubsystem(9);
}
