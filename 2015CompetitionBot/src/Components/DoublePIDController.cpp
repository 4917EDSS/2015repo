/*
 * DoublePIDController.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: TEAM 4917
 */

#include "DoublePIDController.h"
#include "RobotParameters.h"

DoublePIDController::DoublePIDController(PIDSource* source, PIDOutput* output, float* modifier) : PIDOutput(){
	speedController = new PIDController(DISTANCE_P_VALUE,DISTANCE_I_VALUE,DISTANCE_D_VALUE, source, output);
	mModifier = modifier;

}

DoublePIDController::~DoublePIDController() {
	// TODO Auto-generated destructor stub
}
void DoublePIDController::PIDWrite(float speed){
	SmartDashboard::PutNumber("speed pid setpoint", speed);
	speedController->SetSetpoint(speed + *mModifier);
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
