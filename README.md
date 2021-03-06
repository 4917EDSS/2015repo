#Release
Welcome to [4917](http://4917.ca)'s code for the 2015 FIRST Robotics Competition. This code made ![this](http://www.chiefdelphi.com/media/img/bdb/bdb2a2d7ad9aa58d076e9557cd43d19a_l.jpg) do [this](http://watchfirstnow.com/archives/123589220). The code is mostly as is after the scramble of the Waterloo and North Bay competitions.

#Naming Conventions

**[Classes](#classes)**  
**[Commands](#commands)**  
**[Command Groups](#command-groups)**  
**[Subsystems](#subsystems)**   
**[OI](#oi)**  
**[CommandBase](#commmand-base)**  
**[RobotParameters](#robotparameters)**  
**[Misc](#misc)**

##Classes
- All class names must be named with a capital letter first.
- File names should match class name exactly without their ```.h``` or ```.cpp``` extensions
- Member variables should only be private and camelcase.
- Public functions must start with a capital letter
- Private functions must start with a lowercase letter
- All ```.h``` files should have an ```#ifndef``` of the form ```ClassName_H```.
- Remember - all Commands and Subsystems are classes!

###Commands
- All command names must end with ```Cmd```
- Commands are to be named imperatively - you are *telling* the robot what to do.
- Commands should be created with "Right click -> New -> Other -> Command" 
- Don't touch the ```.h``` file unless permission from a mentor is given.

Example names: ```DriveWithJoystickCmd``` ```WinGameCmd```

Example Command ```.h``` file:
```C++
#ifndef WinGameCmd_H
#define WinGameCmd_H

#include "../CommandBase.h"

class WinGameCmd: public CommandBase {
public:
	WinGameCmd();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
```

###Command Groups
- All command group names must end with ```Grp```
- Command groups are to be named imperatively - you are *telling* the robot what to do.
- It should be a high level description of what the end goal is - for example ```CloseArmsThenIntakeUntilLimitSwitchGrp``` is a bad name, while ```BringBoxToBackGrp``` is good.


###Subsystems
- All subsystem names must end with ```Sub```
- All public functions defined in a subsystem must start with a capital letter. 
- Whenever possible, avoid variables like ```motor1``` - these are only acceptable when ```1``` and ```2``` will always be tied together
- Commands should be created with "Right click -> New -> Other -> Subsystem"
- Channels should be passsed into constructor with form ```internalPrivateVarNameC``` (C stands for Channel)
- ```void InitDefaultCommand()``` should be removed unless being used.

Example names: ```DrivetrainSub``` ```DestroyerSub```

Example Subsystem ```.h``` file:
```C++
#ifndef DestroyerSub_H
#define DestroyerSub_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DestroyerSub: public Subsystem 
{
private:
	Talon* hammerMotor;
	Talon* chainSawMotor;
	Encoder* hammerEncoder;
	int destroyedOpponents;
	float percentageDestroyed;
	int hammerTime(int teamNumber);
	//BE VERY CAREFUL WITH THIS COMMAND!! 02/12/2015 never forget :'(
	void galinaHammerTime();
public:
	DestroyerSub(int hammerMotorC, int chainSawMotorC, int hammerEncoderC);
	void StartUpChainSaw(float speed);
	void ShutDownChainSaw(float speed);
	int DestroyedOpponents();
	void ObliterateOpponents(bool galinaMode);
	void InitDefaultCommand();
};

#endif

```
##OI
- OI has two types of variables - operator and driver variables. 
  * Any ```Joystick*``` or ```JoystickButton*``` must have the corresponding ```o``` or ```d``` prepended
  * You must append a ```Btn``` for a ```JoystickButton*``` (ie ```JoystickButton* oIntakeToggleBtn```)
  * You must append a ```Controller``` for a ```Joystick*``` (ie ```JoystickButton* oController```)
- For ```#define``` (note these rules may cause a seemingly redundant define, that is okay)
  * You must prepend an upper case ```O``` or ```D``` depending on which person will use the ```define```
  * You must append a ```Btn``` for a button number (ie ```#define OIntakeToggleBtn 2``` - this will correspond closely to the ```JoystickButton*``` variable name, with only the first letter caps difference)
  * You must append a ```Port``` for a port number (ie ```#define DControllerPort 2```)
  * You must append a ```Axis``` for an axis number (ie ```#define OHorizontalAxis 2```)
- For getters on the OI, the format is ```O``` or ```D``` followed by ```Get```
  * If you are getting a controller's axis, then ```Hor``` or ```Vert``` follow ```GetRight``` or ```GetLeft``` (ie ```float OGetRightHor()```)
  * If you are getting some other analog value, then ```Val``` must follow what you are getting (ie ```float OGetTriggerVal()```)
  * If you are getting a button press (you must ask a mentor before doing this) then the button's name is the end (ie ```bool OGetIntakeToggleBtn```)

##CommandBase
- CommandBase holds the acutal robot's subsystems - these variables should follow the naming convention
  *  ```r``` (for robot) followed by the subsystem's class name (ie ```DestroyerSub* rDestroyerSub```)
- All other ```#define``` in CommandBase are ports for I/O
  * For PWM ports, append ```PWM``` (ie ```#define ArmLeftMotorPWM 1```)
  * For Digital I/O ports, append ```DIO``` (ie ```#define IntakeLimitSwitchDIO 1```)
  * For pnuematic outputs ports, append ```PNC``` (ie ```#define LockSolenoidPNC 1```)
  * For analog input ports, append ```AIN``` (ie ```#define HammerPotentiometerAIN 1```)
  * You can tell which input port type you should be using by looking at where you are plugged into the RoboRIO

##RobotParameters
- To define parameters that will be used throughout operation, such as constants for encoder heights
- The naming convention here is to use all caps, with underscores seperating words
- The name should describe what the constant is (ie ```#define ARMS_OPEN_TIME 1337```)
- For Encoder values, append ```_EV``` (ie ```#define EXCHANGE_TOTE_LEVEL_EV 12345```)

##Misc
- When passing a left and right parameter, left is **always** the first one you should pass.
- When passing a top and bottom parameter, top is **always** the first one you should pass.
```
                                                                                                 
              @@:                        @@@:                                                    
              @@@@@+                      @@@@@#                                                 
               @@;;+@@@@'                  @@+;+@@@@@+           `+@@@@@@@@@@@@@@@@@@+           
                @@+'''':'#@@@@@@#',.``      +@@@;'';;++########+';:;;''''''''''''''';;+@@@@+     
                 '@@''''';''''';;;''++#############''''''''''''''''''''''''''''''''''@+;'''@@@;  
                   .@@#;'''@@@#';;;''''''''''''''''''''''''''''''''''''''''''+@@''''''@@@@;''@@@ 
                      ;@@@';'';+@@@@@@@@@@@+;;;;;;''''''''''''''''''';;'#@@@@@@@''''''@@@@@'''@@@
                          `+@@@@';;'';;;'++@@@@@@@@@#+';;;:::;;;;+#@@@@@@@@@#';''''';#@@@@@#''@@@
                                 ,'#@@@@@@@@@#;:+@@@@#+++++++##@@@@@@@#+:;+@@###@@@@@@@@@@+''#@@ 
                                      :@@@:+@+;;'''''''''''''''''''';'#@@;@@+:;#@@@@@@#'':'@@@.  
                                    @@@@@';@'''''''''''''''''''''''''''''';@'''''''@@@@@@#       
                                  '@@@;'@;'@''''''''''''''''''''''''''''''';'#@;'@@@@'           
                                 @@@:@';@''#'''''''''''''''''''''''''''''#';@''@@@               
                                 @@@@@@@:@;''''@@+++@@+'''''#@;;''''''#''@''@@''@@@              
                                 #@@@@@@@@@';@';#@@@@'''#'''''''@@@+@@;'#@''@@+''@@              
                                 @@@'';+@@@@@#'@@@@@@@'';;+#@@@#+@@@@@@@@@;;@@@''@@              
`                              ;@@@''''''''@@@@@+;+@@+;;''''''''''';;''+#@@@@@@;@@@              
   @@@@@@@+;                 @@@+;'''@+''''';@@@@@;@@:;;'@@+;'''''''''''''''''';;'#@@            
      :@@@:;;'+@@@@@@@''+@@@+;'''''@@@''''''''@@@@@+@@;;@#''';+@#;'''';'''@@''@@''@@@            
         ;@@@@@@@@#+';;:;+@@#'''#@@@;;@@';'''';@@@@++@+:+@+;'''''';+@@@@'#@''@@''@@@             
            @@@@;''+++#@@@@@@#';:;+@@@@'@@''''''';+@@@@+;##;''''''''''';+@@';@+'#@@              
              @@@@@@@@@@@@##';;;;;+@@@';;'@@;;''''''':@@@@@#:''''''''''''''';@@+@@@              
                @@@@@@@@@@+'::;;'@@@@#;;;;+@@;;;@@@@@@@@@@@@@@@@''''''''';;@@@@@@:               
                    ,+@@@@@#++';;;;''''';;'##+'';##+;+@@@@@@+. .'@@@#@@@@'.                      
              ;@@@@@@@+###++''';;;;;''''''''''''''''''''';+@@@;                                  
                         ````.;##@@@@@@@@@@@@##+;;;;'''''''''';#@@#                              
                                                ,##@@@@@@@@+;''''';#@@#                          
                                                            ,'#@@@@@'';#@@:                      
                                                                     .;@@@@@@#                   
                                                                            `;@@@.               
                                                                                  '@`            
                                                                                                 

```
