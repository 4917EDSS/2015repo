#include "InputButton.h"
#include "../Robotmap.h"

InputButton::InputButton(int Channel): Subsystem("InputButton") {
	RightButton = new DigitalInput(Channel);
	
	
}
bool InputButton::IsPressed(){
    	return !RightButton->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
