/*
 * DoublePIDController.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: TEAM 4917
 */

#include "DoublePIDController.h"
#include "RobotParameters.h"

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
	motor->Set(speed + (speed/MAX_SPEED_EV)*(*mModifier));

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
