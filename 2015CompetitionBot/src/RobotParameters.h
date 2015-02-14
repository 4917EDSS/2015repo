#ifndef ROBOT_PARAMETERS_H
#define ROBOT_PARAMETERS_H


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

#define LOCKS_OPEN_DELAY .01
#define LOCKS_CLOSE_DELAY .3
#define ARMS_OPEN_DELAY .3

#define ENCODER_ZERO_IN_CYCLES 10

#define DRIVE_DIFFERENCE_TOLERANCE 0.4
#define MIN_SPEED_TO_MOVE_MAST 0.35

//LIFT ENCODER VALUES
#define LIFT_ENCODER_SLOWDOWN_DISTANCE 200
#define BOTTOM_LIMIT_EV 0
#define SCORE_HEIGHT_EV 355  //step?
#define FIRST_CONTACT_EV 912
#define TRANSFER_EV 2426
#define INTERFERENCE_LOCKOUT_EV 2600
#define ARM_LOCKOUT_EV 4622
#define TWO_STACK_EV 3218
#define THREE_STACK_EV 4702
#define FOUR_STACK_EV 6203
#define FIVE_STACK_EV 6296
#define SIX_STACK_EV 6296
#define TOP_LIMIT_EV 6296 //5 and 6 stacks not tested.
#define ONE_METER_EV 5000

//DRIVE ENCODER VALS
//millimeters/tick and centimeters/tick
#define MM_PER_EV_TICK 2.75
//go forward this much on one side and reverse the same amount on the other for a 90 degree turn
#define NINETY_DEGREE_TURN_EV 2700
//So 30 ticks on the encoder forward and back means 1 degree of the entire robot turning.
#define DEGREE_ROTATE_TO_ENCODER_FACTOR 30



#define CAMERA_NAME "cam1"


#define CTRLR_HOR_INTAKE_TOLERANCE 0.8
#endif
