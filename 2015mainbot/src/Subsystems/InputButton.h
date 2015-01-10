#ifndef INPUTBUTTON_H
#define INPUTBUTTON_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * 
 * 
 * 
 */
class InputButton: public Subsystem {
private:
	DigitalInput *RightButton;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	InputButton(int Channel);
	bool IsPressed();
};

#endif
