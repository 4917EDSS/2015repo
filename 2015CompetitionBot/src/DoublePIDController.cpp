/*
 * DoublePIDController.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: TEAM 4917
 */

#include <DoublePIDController.h>

DoublePIDController::DoublePIDController(PIDSource* source, PIDOutput* output) : PIDOutput(){
	speedController = new PIDController(0.0003,0.000075,0, source, output);

}

DoublePIDController::~DoublePIDController() {
	// TODO Auto-generated destructor stub
}
void DoublePIDController::PIDWrite(float speed){
	SmartDashboard::PutNumber("speed pid setpoint", speed);
	speedController->SetSetpoint(speed);
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
