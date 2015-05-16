/*
 * WARNING : OLD OBJECT. UNUSED. 
 */

#include "DoublePIDController.h"
#include "RobotParameters.h"

#define DISTANCE_P_VALUE 0.04
#define DISTANCE_I_VALUE 0.0
#define DISTANCE_D_VALUE 0.1
#define DISTANCE_F_VALUE 0

DoublePIDController::DoublePIDController(PIDSource* source, Talon* output, float* modifier) : PIDOutput(){
	motor = output;
	speedController = new PIDController(DISTANCE_P_VALUE,DISTANCE_I_VALUE,DISTANCE_D_VALUE, source, output);
	mModifier = modifier;

}

DoublePIDController::~DoublePIDController() {
	// TODO Auto-generated destructor stub
}
void DoublePIDController::PIDWrite(float speed){
	SmartDashboard::PutNumber("speed pid setpoint", speed + *mModifier);
	//speedController->SetSetpoint(speed + *mModifier);
	motor->Set(speed + *mModifier);

}
void DoublePIDController::SetAbsoluteTolerance(double tolerance){
	speedController->SetAbsoluteTolerance(tolerance);
}
void DoublePIDController::SetOutputRange(double lower, double upper){
	speedController->SetOutputRange(lower, upper);
}
void DoublePIDController::Enable(){
	speedController->Enable();
}
void DoublePIDController::Disable(){
	speedController->Disable();
}
PIDController* DoublePIDController::GetPIDController() {
	return speedController;
}
