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
#include "Commands/DriveTurnCmd.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "Commands/AutoThreeToteGrp.h"
#include "Commands/AutoDriveForwardsGrp.h"
#include "Commands/AutoOneBinGrp.h"
#include "Commands/AutoOneToteOneBinGrp.h"

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
		SmartDashboard::PutData("Go forward 2 meters half speed", new DriveStraightCmd(2000, 0.5));
		SmartDashboard::PutData("Go backward 2 meters half speed", new DriveStraightCmd(-2000, 0.5));
		SmartDashboard::PutData("Go forward 3 meters full speed", new DriveStraightCmd(3000, 1.0));
		SmartDashboard::PutData("clockwise half speed 90 degrees", new DriveTurnCmd(90,true,0.5));
		SmartDashboard::PutData("counterclockwise full speed 180 deg",new DriveTurnCmd(180,false,1.0));
		SmartDashboard::PutData("Go backwards 4 meters half speed", new DriveStraightCmd(4000, -0.5));
		SmartDashboard::PutData("counterclockwise full speed 180 deg", new DriveTurnCmd(180,false,1.0));
		SmartDashboard::PutData("AUTO: Three tote, drive to auto zone, and drop", new AutoThreeToteGrp());
		SmartDashboard::PutData("AUTO: Basic Drive forward two meters", new AutoDriveForwardsGrp());
		SmartDashboard::PutData("AUTO: Drives straight, moves a bin", new AutoOneBinGrp());
		SmartDashboard::PutData("AUTO: picks up one tote and bin, drives to auto zone", new AutoOneToteOneBinGrp());


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
		SmartDashboard::PutData("drivetrain", CommandBase::rDrivetrainSub);
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		SmartDashboard::PutBoolean("Locks Open",CommandBase::rLiftSub->GetLocks()==LOCKS_OPEN);
		SmartDashboard::PutBoolean("Jaws open",CommandBase::rLiftSub->GetJaws()==JAWS_OPEN);
		SmartDashboard::PutBoolean("Arms open",CommandBase::rIntakeSub->GetArms()==ARMS_OPEN);
		SmartDashboard::PutBoolean("top limit",CommandBase::rLiftSub->GetTopLimitSwitch());
		SmartDashboard::PutBoolean("bottom limit",CommandBase::rLiftSub->GetBottomLimitSwitch());
		SmartDashboard::PutBoolean("intake limit",CommandBase::rIntakeSub->IsLimitHit());
		SmartDashboard::PutNumber("Left Wheel raw Encoder",CommandBase::rDrivetrainSub->GetRawLeftEnc());
		SmartDashboard::PutNumber("Right Wheel raw Encoder",CommandBase::rDrivetrainSub->GetRawRightEnc());
		SmartDashboard::PutNumber("Left Wheel dis Encoder",CommandBase::rDrivetrainSub->GetLeftEnc());
		SmartDashboard::PutNumber("Right Wheel dis Encoder",CommandBase::rDrivetrainSub->GetRightEnc());
		SmartDashboard::PutBoolean("Drive Style", CommandBase::rDrivetrainSub->GetControls());
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

