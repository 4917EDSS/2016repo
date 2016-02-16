#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

#define CAMERA_NAME "cam2"

#define TANK_DRIVE_CONTROLS 1
#define FPS_DRIVE_CONTROLS 2

#define ACCELERATION_THRESHOLD 0.1

#define ROTATE_MARGIN 10

#define MIDDLE_CAMERA_X 160.0

#define TARGET_RANGE 40

#define DRIVE_SENSITIVITY 2.5      //The higher the number, the less sensitive.

//Some bool constants used for code readability
#define IS_DRIVE true
#define IS_SHIFTER false

/***********************************************************************
 ************************* ENCODER VALUES ******************************
 ***********************************************************************/
// TURRET ROTATE
// TODO: get these values
#define MAX_TURRET_ROTATE_EV 400
#define MAX_TURRET_ROTATE_INTERFERENCE_EV 200
#define ROTATE_SLOW 0.25

// TURRET HOOD
#define HOOD_INTERFERENCE_EV 200
#define MAX_HOOD_HEIGHT_EV 400

// DRIVETRAIN
//go forward this much on one side and reverse the same amount on the other for a 90 degree turn.
//TODO: update this once the robot is finalized.
#define DISTANCE_PER_DEGREE (745.0/90.0)



#endif
