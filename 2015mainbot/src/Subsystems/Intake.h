#ifndef INTAKE_H
#define INTAKE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Subsystems/GeneralAirToggle.h"

/**
 * 
 * 
 * 
 */
class Intake: public Subsystem {
	private:
		Talon* armRight;
		Talon* armLeft;
		GeneralAirToggle* openClose;
		DigitalInput* intakeLimit;
		
	public:
		Intake(int armleft_channel, int armright_channel, int solenoidright_channel, int solenoidleft_channel, int limitswitch_channel);
		void SetMotor(float speed);
		void SetArms(bool isout);
		bool GetArms();
		void ToggleArms();
		bool IsTouched();
};
#endif

