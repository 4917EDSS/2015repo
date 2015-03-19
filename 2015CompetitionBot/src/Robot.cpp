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
#include "Commands/AutoThreeToteOneBinGrp.h"
#include "Commands/AutoDriveForwardsGrp.h"
#include "Commands/AutoOneBinGrp.h"
#include "Commands/AutoOneToteOneBinGrp.h"
#include "Commands/ResetDrivetrainCmd.h"
#include "Commands/AutoOneToteGrp.h"
#include "Commands/AdjustPIDCmd.h"
#include "Commands/AutoDropStackGrp.h"
#include "COmmands/AutoDoNothingCmd.h"
#include "Subsystems/IMU.h"
#include "Subsystems/IMUAdvanced.h"
#include "Subsystems/AHRS.h"

class Robot: public IterativeRobot
{
    NetworkTable *table;
#if defined(ENABLE_AHRS)
    AHRS *imu;
#elif defined(ENABLE_IMU_ADVANCED)
    IMUAdvanced *imu;
#else // ENABLE_IMU
    IMU *imu;
#endif
    SerialPort *serial_port;
    bool first_iteration;

private:
	LiveWindow *lw;
	SendableChooser *autoOptions;
	CommandGroup *autoCommand;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();

		CameraServer::GetInstance()->SetQuality(50);
		//the camera name (ex "cam0") can be found through the roborio web interface
		CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
		autoOptions = new SendableChooser();
		autoOptions->AddDefault("Drive forward starting at auto line", new AutoDriveForwardsGrp());
		autoOptions->AddObject("Moves one bin to auto zone", new AutoOneBinGrp());
		autoOptions->AddObject("Moves one tote to auto zone", new AutoOneToteGrp());
		autoOptions->AddObject("Moves one bin and one tote to auto zone", new AutoOneToteOneBinGrp());
		autoOptions->AddObject("Moves three tote and one bin to auto zone", new AutoThreeToteOneBinGrp());
		autoOptions->AddObject("Moves all three totes to auto zone, assuming two bins are moved", new AutoThreeToteGrp());
		autoOptions->AddObject("Does nothing", new AutoDoNothingCmd());
		SmartDashboard::PutData("Autonomous selector", autoOptions);
		autoCommand = 0;

		//CameraServer::GetInstance()->SetQuality(50);
		//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
		SmartDashboard::PutData("Intake Until Limit Command", new IntakeUntilLimitCmd());
		SmartDashboard::PutData("Set Locks Open", new SetLocksCmd(LOCKS_OPEN));
		SmartDashboard::PutData("Set Locks Closed", new SetLocksCmd(LOCKS_CLOSED));
		SmartDashboard::PutData("Set Arms Closed", new SetArmsCmd(ARMS_CLOSED));
		SmartDashboard::PutData("Go forward 2 meters half speed", new DriveStraightCmd(2000, MAX_SPEED_EV/2));
		SmartDashboard::PutData("Go backward 2 meters half speed", new DriveStraightCmd(-2000, MAX_SPEED_EV/2));
		SmartDashboard::PutData("Go forward 3 meters full speed", new DriveStraightCmd(3000, MAX_SPEED_EV));
		SmartDashboard::PutData("RESET drivetrain encoders", new ResetDrivetrainCmd());
		SmartDashboard::PutData("clockwise half speed 90 degrees", new DriveTurnCmd(90,true,MAX_SPEED_EV/2));
		SmartDashboard::PutData("counterclockwise full speed 180 deg",new DriveTurnCmd(180,false,MAX_SPEED_EV));
		SmartDashboard::PutData("Go backwards 4 meters half speed", new DriveStraightCmd(-4000, MAX_SPEED_EV/2));
		SmartDashboard::PutData("counterclockwise full speed 180 deg", new DriveTurnCmd(180,false,MAX_SPEED_EV));
		SmartDashboard::PutData("AUTO: One Tote, Drive to auto zone", new AutoOneToteGrp());
		SmartDashboard::PutData("AUTO: Three tote, drive to auto zone, and drop", new AutoThreeToteGrp());
		SmartDashboard::PutData("AUTO: Basic Drive forward two meters", new AutoDriveForwardsGrp());
		SmartDashboard::PutData("AUTO: Drives straight, moves a bin", new AutoOneBinGrp());
		SmartDashboard::PutData("AUTO: picks up one tote and bin, drives to auto zone", new AutoOneToteOneBinGrp());

		SmartDashboard::PutData("Set P and I", new AdjustPIDCmd());
		SmartDashboard::PutNumber("p value", CommandBase::rDrivetrainSub->GetP()*1000);
		SmartDashboard::PutNumber("i value", CommandBase::rDrivetrainSub->GetI()*1000);
		SmartDashboard::PutNumber("d value", CommandBase::rDrivetrainSub->GetD()*1000);


        serial_port = new SerialPort(4800, SerialPort::kMXP);
		imu = new IMU(serial_port,60);

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
		bool is_calibrating = imu->IsCalibrating();
		if ( !is_calibrating ) {
			Wait( 0.3 );
			imu->ZeroYaw();
		}
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
		SmartDashboard::PutNumber("P on drivetrain",CommandBase::rDrivetrainSub->GetP()*1000);
		SmartDashboard::PutNumber("I on drivetrain",CommandBase::rDrivetrainSub->GetI()*1000);
		SmartDashboard::PutNumber("D on drivetrain",CommandBase::rDrivetrainSub->GetD()*1000);
		SmartDashboard::PutBoolean("left on target", CommandBase::rDrivetrainSub->isLeftOnTarget());
		SmartDashboard::PutBoolean("right on target", CommandBase::rDrivetrainSub->isRightOnTarget());
		SmartDashboard::PutBoolean( "IMU_Connected", imu->IsConnected());
		SmartDashboard::PutNumber("IMU_Yaw", imu->GetYaw());
		SmartDashboard::PutNumber("IMU_Pitch", imu->GetPitch());
		SmartDashboard::PutNumber("IMU_Roll", imu->GetRoll());
		SmartDashboard::PutNumber("IMU_CompassHeading", imu->GetCompassHeading());
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

