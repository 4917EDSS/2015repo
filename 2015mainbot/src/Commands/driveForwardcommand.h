#ifndef driveForwardcommand_H
#define driveForwardcommand_H

#include "Joystick.h"
#include "../CommandBase.h"
#include "../OI.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class driveForwardcommand : public CommandBase {
public:
	driveForwardcommand(){
		
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		//m_drivetrain->drive(oi->rightStick->GetX(),oi->rightStick->GetY());
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
		m_drivetrain->drive(0,0);		
	}
	virtual void Interrupted(){
		m_drivetrain->drive(0,0);
		
		
	}
};

#endif
