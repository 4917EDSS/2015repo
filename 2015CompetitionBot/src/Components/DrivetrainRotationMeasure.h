/*
 * DrivetrainRotationMeasure.h
 *
 *  Created on: Mar 2, 2015
 *      Author: TEAM 4917
 */

#ifndef SRC_COMPONENTS_DRIVETRAINROTATIONMEASURE_H_
#define SRC_COMPONENTS_DRIVETRAINROTATIONMEASURE_H_

#include <WPILib.h>

class DrivetrainRotationMeasure: public PIDSource {
	Encoder* leftEncoder;
	Encoder* rightEncoder;
public:
	DrivetrainRotationMeasure(Encoder* left, Encoder* right);
	virtual ~DrivetrainRotationMeasure();
	double PIDGet();
};

#endif /* SRC_COMPONENTS_DRIVETRAINROTATIONMEASURE_H_ */
