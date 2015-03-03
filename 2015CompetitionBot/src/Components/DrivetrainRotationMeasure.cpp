/*
 * DrivetrainRotationMeasure.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: TEAM 4917
 */

#include <Components/DrivetrainRotationMeasure.h>

DrivetrainRotationMeasure::DrivetrainRotationMeasure(Encoder* left, Encoder* right) {
	leftEncoder = left;
	rightEncoder = right;
}
DrivetrainRotationMeasure::~DrivetrainRotationMeasure() {
	// TODO Auto-generated destructor stub
}
double DrivetrainRotationMeasure::PIDGet(){
	return fabs(rightEncoder->GetDistance()) - fabs(leftEncoder->GetDistance());
}

