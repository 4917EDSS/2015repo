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
InputButton* CommandBase::inputbutton = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
        // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	m_intake = new Intake(7,8,1,2);
	m_drivetrain = new Drivetrain(1, 3, 5, 2, 4, 6);
	inputbutton = new InputButton(1);
	oi = new OI();
}
