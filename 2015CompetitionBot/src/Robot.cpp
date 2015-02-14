#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "RobotParameters.h"
#include "Commands/IntakeUntilLimitCmd.h"
#include "Commands/SetLiftHeightCmd.h"
#include "Commands/SetLocksCmd.h"
#include "Commands/SetArmsCmd.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/PickUpBoxGrp.h"
#include "Commands/ToggleJawsCmd.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	SendableChooser *autoOptions;
	CommandGroup *autoCommand;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();

		autoOptions = new SendableChooser();
		autoOptions->AddDefault("Pick Up Box Default Test", new PickUpBoxGrp());
		autoOptions->AddObject("Toggle Jaws Object Test", new ToggleJawsCmd());
		SmartDashboard::PutData("Autonomous Delay Options", autoOptions);

		CameraServer::GetInstance()->SetQuality(50);
		//the camera name (ex "cam0") can be found through the roborio web interface
		CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
		SmartDashboard::PutData("intake Until Limit Command", new IntakeUntilLimitCmd());
		SmartDashboard::PutData("set height to 2000", new SetLiftHeightCmd(2000));
		SmartDashboard::PutData("set height to -2000", new SetLiftHeightCmd(-2000));
		SmartDashboard::PutData("set height to 500", new SetLiftHeightCmd(500));
		SmartDashboard::PutData("set height to -500", new SetLiftHeightCmd(-500));
		SmartDashboard::PutData("Set Locks Open", new SetLocksCmd(LOCKS_OPEN));
		SmartDashboard::PutData("Set Locks Closed", new SetLocksCmd(LOCKS_CLOSED));
		SmartDashboard::PutData("Set Arms Closed", new SetArmsCmd(ARMS_CLOSED));

		// TODO: initialize all air solenoids to values

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autoCommand = (CommandGroup*)autoOptions->GetSelected();
		autoCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autoCommand != NULL)
			autoCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		SmartDashboard::PutBoolean("Locks",CommandBase::rLiftSub->GetLocks());
		SmartDashboard::PutBoolean("Jaws",CommandBase::rLiftSub->GetJaws());
		SmartDashboard::PutBoolean("Arms",CommandBase::rIntakeSub->GetArms());
		SmartDashboard::PutNumber("Left Wheel Encoder",CommandBase::rDrivetrainSub->GetLeftEnc());
		SmartDashboard::PutNumber("Right Wheel Encoder",CommandBase::rDrivetrainSub->GetRightEnc());
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

