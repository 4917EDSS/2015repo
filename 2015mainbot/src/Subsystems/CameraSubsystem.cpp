#include "CameraSubsystem.h"
#include "../RobotMap.h"
#include "CameraServer.h"

CameraSubsystem::CameraSubsystem() :
		Subsystem("CameraSubsystem")
{
	//microsoftCamera = new CameraServer();
}

void CameraSubsystem::StartCapture(){
	CameraServer::GetInstance()->SetQuality(50);
	//the camera name (ex "cam0") can be found through the roborio web interface
	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
}

void CameraSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
