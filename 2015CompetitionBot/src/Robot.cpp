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
#include "Commands/ResetDrivetrainCmd.h"
#include "Commands/AutoOneToteGrp.h"
#include "Commands/AdjustPIDCmd.h"

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
		SmartDashboard::PutData("Set Locks Open", new SetLocksCmd(LOCKS_OPEN));
		SmartDashboard::PutData("Set Locks Closed", new SetLocksCmd(LOCKS_CLOSED));
		SmartDashboard::PutData("Set Arms Closed", new SetArmsCmd(ARMS_CLOSED));
		SmartDashboard::PutData("Go forward 2 meters half speed", new DriveStraightCmd(2000, MAX_SPEED_EV/2));
		SmartDashboard::PutData("Go backward 2 meters half speed", new DriveStraightCmd(-2000, 500));
		SmartDashboard::PutData("Go forward 3 meters full speed", new DriveStraightCmd(3000, MAX_SPEED_EV));
		SmartDashboard::PutData("RESET drivetrain encoders", new ResetDrivetrainCmd());
		SmartDashboard::PutData("clockwise half speed 90 degrees", new DriveTurnCmd(90,true,0.5));
		SmartDashboard::PutData("counterclockwise full speed 180 deg",new DriveTurnCmd(180,false,1.0));
		SmartDashboard::PutData("Go backwards 4 meters half speed", new DriveStraightCmd(-4000, 0.5));
		SmartDashboard::PutData("counterclockwise full speed 180 deg", new DriveTurnCmd(180,false,1.0));
		SmartDashboard::PutData("AUTO: One Tote, Drive to auto zone", new AutoOneToteGrp());
		SmartDashboard::PutData("AUTO: Three tote, drive to auto zone, and drop", new AutoThreeToteGrp());
		SmartDashboard::PutData("AUTO: Basic Drive forward two meters", new AutoDriveForwardsGrp());
		SmartDashboard::PutData("AUTO: Drives straight, moves a bin", new AutoOneBinGrp());
		SmartDashboard::PutData("AUTO: picks up one tote and bin, drives to auto zone", new AutoOneToteOneBinGrp());
		SmartDashboard::PutData("inc p big", new AdjustPIDCmd());
		SmartDashboard::PutNumber("p value", CommandBase::rDrivetrainSub->GetP()*1000);
		SmartDashboard::PutNumber("i value", CommandBase::rDrivetrainSub->GetI()*1000);


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
		SmartDashboard::PutNumber("Left Wheel Encoder Speed",CommandBase::rDrivetrainSub->GetLeftEncoderRate());
		SmartDashboard::PutNumber("Right Wheel Encoder Speed",CommandBase::rDrivetrainSub->GetRightEncoderRate());
		SmartDashboard::PutBoolean("Drive Style", CommandBase::rDrivetrainSub->GetControls());
		SmartDashboard::PutNumber("P on drivetrain",CommandBase::rDrivetrainSub->GetP());
		SmartDashboard::PutNumber("I on drivetrain",CommandBase::rDrivetrainSub->GetI());
		SmartDashboard::PutBoolean("left on target", CommandBase::rDrivetrainSub->isLeftOnTarget());
		SmartDashboard::PutBoolean("right on target", CommandBase::rDrivetrainSub->isRightOnTarget());
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

