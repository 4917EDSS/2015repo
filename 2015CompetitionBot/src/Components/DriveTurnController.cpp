/*
 * PIDTurnController.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: TEAM 4917
 */

#include <Components/DriveTurnController.h>
#include "../CommandBase.h"

DriveTurnController::DriveTurnController() {
	// TODO Auto-generated constructor stub

}

DriveTurnController::~DriveTurnController() {
	// TODO Auto-generated destructor stub
}
void DriveTurnController::PIDWrite(float offset){
	CommandBase::rDrivetrainSub->SetTurnModifier(offset);
}

