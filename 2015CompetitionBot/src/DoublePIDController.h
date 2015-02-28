/*
 * DoublePIDController.h
 *
 *  Created on: Feb 21, 2015
 *      Author: TEAM 4917
 */

#ifndef SRC_DOUBLEPIDCONTROLLER_H_
#define SRC_DOUBLEPIDCONTROLLER_H_

#include <WPILib.h>

class PIDSource;

class DoublePIDController: public PIDOutput {
private:
	PIDController* speedController;
public:
	DoublePIDController(PIDSource* source, PIDOutput* output);
	virtual ~DoublePIDController();
	void PIDWrite(float speed);
	void SetAbsoluteTolerance(double tolerance);
	void SetOutputRange(double lower, double upper);
	PIDController* GetPIDController();
	void Enable();
	void Disable();
};

#endif /* SRC_DOUBLEPIDCONTROLLER_H_ */
