#ifndef ROBOT_PARAMETERS_H
#define ROBOT_PARAMETERS_H


// #define COMPETITION_BOT for big green bot
// #define PRACTICE_BOT for practice one
#define PRACTICE_BOT



#define LIFT_ZERO_BOX 0.5
#define LIFT_ONE_BOX 1.5
#define LIFT_TWO_BOX 2.5
#define LIFT_THREE_BOX 3.5
#define LIFT_FOUR_BOX 4.5
#define LIFT_TOLERANCE 20
#define LOCKS_OPEN false
#define LOCKS_CLOSED true
#define ARMS_CLOSED true
#define ARMS_OPEN false
#define JAWS_OPEN false
#define JAWS_CLOSED true

#define TANK_DRIVE_CONTROLS 1
#define FPS_DRIVE_CONTROLS 2

#define ACCELERATION_THRESHOLD 0.1

#define CAMERA_NAME "cam1"

#define CTRLR_HOR_INTAKE_TOLERANCE 0.8
#define DRIVE_DIST_TOLERANCE 50

#define LOCKS_CLOSE_DELAY .3
#define JAWS_CLOSE_DELAY .6
#define ARMS_OPEN_DELAY .3
#define ARMS_CLOSE_DELAY .6

#define ENCODER_ZERO_IN_CYCLES 10
#define STALL_RECHECK_RATE 4

#define SLOW_MAST_SPEED 0.3
#define STALLED_SPEED_BONUS 0.005
#define DRIVE_DIFFERENCE_TOLERANCE 0.2
#define MIN_SPEED_TO_MOVE_MAST 0.35

//AUTO DEFINES
#define DRIVE_INTO_AUTON_ZONE_MM 1500
#define DRIVE_CENTER_TO_CENTER 3351
#define DRIVE_ONE_GREEN_BIN 300
#define DRIVE_ONE_TOTE 711
#define DISTANCE_BETWEEN_TOTES 1850
#define STAGING_TO_AUTO_DISTANCE 2178
#define BACK_OFF_DISTANCE 100

#define ENCODER_CONVERSION_FACTOR 4

//ONLY FOR BOT SPECIFIC STUFF
#ifdef PRACTICE_BOT

//LIFT ENCODER VALUES

	#define BOTTOM_LIMIT_EV 0
	#define SCORE_HEIGHT_EV 355  //step?
	#define FIRST_CONTACT_EV 912
	#define TRANSFER_EV 2426
	#define INTERFERENCE_LOCKOUT_EV 2600
	#define GREEN_BIN_HANDLES_EV 2280
	#define GREEN_BIN_ABOVE_TOTE_EV 4100
	#define TOTE_CHUTE_INTAKE_EV 3700
	#define ONE_STACK_EV 1750
	#define TWO_STACK_EV 3218
	#define THREE_STACK_EV 4702
	#define FOUR_STACK_EV 6203
	#define FIVE_STACK_EV 6296
	#define SIX_STACK_EV 6296
	#define TOP_LIMIT_EV 6296 //5 and 6 stacks not tested.

	#define LOCK_GRAB_STACK_EV 2100


	#define LIFT_ENCODER_SLOWDOWN_DISTANCE 200

	//DRIVE ENCODER VALS
	//millimeters/tick
	#define DISTANCE_PER_PULSE 2000.0/7920.0
	//go forward this much on one side and reverse the same amount on the other for a 90 degree turn
	#define DISTANCE_PER_DEGREE 745.0/90.0

	#define MAX_SPEED_EV 2700
#endif

//ONLY FOR BOT SPECIFIC STUFF
#ifdef COMPETITION_BOT
	//LIFT ENCODER VALUES
	#define BOTTOM_LIMIT_EV 0
	#define SCORE_HEIGHT_EV 680  //scoring platform
	#define FIRST_CONTACT_EV 914
	#define TRANSFER_EV 2358
	#define INTERFERENCE_LOCKOUT_EV 2525
	#define TOTE_CHUTE_INTAKE_EV 3700 // NEEDS A CORRECT VALUE
	#define GREEN_BIN_HANDLES_EV 2280
	#define GREEN_BIN_ABOVE_TOTE_EV 4100
	#define ONE_STACK_EV 1750
	#define TWO_STACK_EV 3223
	#define THREE_STACK_EV 4700
	#define FOUR_STACK_EV 6035
	#define FIVE_STACK_EV 7550
	#define TOP_LIMIT_EV 7884 //5 and 6 stacks not tested.
	#define LIFT_ENCODER_SLOWDOWN_DISTANCE 100	//200

	#define LOCK_GRAB_STACK_EV 2100  //not tested



	//DRIVE ENCODER VALS
	//millimeters/tick
	#define DISTANCE_PER_PULSE 2000.0/10700.0
	//go forward this much on one side and reverse the same amount on the other for a 90 degree turn
	#define DISTANCE_PER_DEGREE
	#define MAX_SPEED_EV 2700

#endif


#endif
