#ifndef INTAKE_H
#define INTAKE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * 
 * 
 * 
 */
class Intake: public Subsystem {
	private:
		Talon* armRight;
		Talon* armLeft;
		Solenoid* armArticulationRight;
		Solenoid* armArticulationLeft;
		
	public:
		Intake(int armleft_channel, int armright_channel, int solenoidright_channel, int solenoidleft_channel);
		void SetMotor(float speed);
		void SetArms(bool isout);
		bool GetArms();
};
#endif

