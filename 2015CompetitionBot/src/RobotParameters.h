#ifndef ROBOT_PARAMETERS_H
#define ROBOT_PARAMETERS_H


// #define COMPETITION_BOT for big green bot
// #define PRACTICE_BOT for practice one
#define COMPETITION_BOT



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
#define DRIVE_DIST_TOLERANCE 100

#define LOCKS_CLOSE_DELAY .3
#define ARMS_OPEN_DELAY .3
#define ARMS_CLOSE_DELAY .3

#define ENCODER_ZERO_IN_CYCLES 10
#define STALL_RECHECK_RATE 4

#define SLOW_MAST_SPEED 0.3
#define STALLED_SPEED_BONUS 0.005
#define DRIVE_DIFFERENCE_TOLERANCE 0.2
#define MIN_SPEED_TO_MOVE_MAST 0.35

//AUTO DEFINES
#define DRIVE_INTO_AUTON_ZONE_MM 2000
#define DRIVE_CENTER_TO_CENTER 3251
#define DRIVE_ONE_GREEN_BIN 533
#define DRIVE_ONE_TOTE 711
#define DISTANCE_BETWEEN_TOTES 2089
#define STAGING_TO_AUTO_DISTANCE 2178
#define BACK_OFF_DISTANCE 700

//ONLY FOR BOT SPECIFIC STUFF
#ifdef PRACTICE_BOT

//LIFT ENCODER VALUES

	#define BOTTOM_LIMIT_EV 0
	#define SCORE_HEIGHT_EV 355  //step?
	#define FIRST_CONTACT_EV 912
	#define TRANSFER_EV 2426
	#define INTERFERENCE_LOCKOUT_EV 2600
	#define TWO_STACK_EV 3218
	#define THREE_STACK_EV 4702
	#define FOUR_STACK_EV 6203
	#define FIVE_STACK_EV 6296
	#define SIX_STACK_EV 6296
	#define TOP_LIMIT_EV 6296 //5 and 6 stacks not tested.
	#define ONE_METER_EV 5000


	#define ENCODER_CONVERSION_FACTOR 4
	#define LIFT_ENCODER_SLOWDOWN_DISTANCE 200

	//DRIVE ENCODER VALS
	//millimeters/tick
	#define DISTANCE_PER_PULSE 0.277
	//go forward this much on one side and reverse the same amount on the other for a 90 degree turn
	#define NINETY_DEGREE_TURN_EV 2700
	//So 30 ticks on the encoder forward and back means 1 degree of the entire robot turning.
	#define DEGREE_ROTATE_TO_ENCODER_FACTOR 30

	//AUTO DEFINES
	#define DISTANCE_BETWEEN_TOTES 2089
#endif

//ONLY FOR BOT SPECIFIC STUFF
#ifdef COMPETITION_BOT
	//LIFT ENCODER VALUES
	#define BOTTOM_LIMIT_EV 0	//0
	#define SCORE_HEIGHT_EV 90	//680  //scoring platform
	#define FIRST_CONTACT_EV 390	//914
	#define TRANSFER_EV 1212	//2358
	#define INTERFERENCE_LOCKOUT_EV 1400  //2525
	#define TWO_STACK_EV 1700	//3223
	#define THREE_STACK_EV 2400	//4700
	#define FOUR_STACK_EV 2900	//6035
	#define FIVE_STACK_EV 3650	//7550
	#define TOP_LIMIT_EV 3800	//7884 //5 and 6 stacks not tested.
	#define LIFT_ENCODER_SLOWDOWN_DISTANCE 100	//200

	#define ONE_METER_EV 5350


	//DRIVE ENCODER VALS
	//millimeters/tick
	#define DISTANCE_PER_PULSE 2000.0/10700.0
	//go forward this much on one side and reverse the same amount on the other for a 90 degree turn
	#define NINETY_DEGREE_TURN_EV 4100
	//So 30 ticks on the encoder forward and back means 1 degree of the entire robot turning.
	#define DEGREE_ROTATE_TO_ENCODER_FACTOR 45.56
	#define ENCODER_CONVERSION_FACTOR 4

#endif


#endif
