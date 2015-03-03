/*
 * PIDTurnController.h
 *
 *  Created on: Mar 2, 2015
 *      Author: TEAM 4917
 */

#ifndef SRC_COMPONENTS_DRIVETURNCONTROLLER_
#define SRC_COMPONENTS_DRIVETURNCONTROLLER_

#include <PIDOutput.h>

class DriveTurnController: public PIDOutput {
public:
	DriveTurnController();
	virtual ~DriveTurnController();
	void PIDWrite(float offset);
};

#endif /* SRC_COMPONENTS_DRIVETURNCONTROLLER_ */
