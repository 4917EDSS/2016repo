#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

#define CAMERA_NAME "cam2"

#define TANK_DRIVE_CONTROLS 1
#define FPS_DRIVE_CONTROLS 2

#define ACCELERATION_THRESHOLD 0.1

#define ROTATE_MARGIN 10

#define MIDDLE_CAMERA_X 120.0

#define TARGET_RANGE 15

#define DRIVE_SENSITIVITY 2.5      //The higher the number, the less sensitive.

#define ROTATE_SLOW 0.25

//Some bool constants used for code readability
#define IS_DRIVE true
#define IS_SHIFTER false

/***********************************************************************
 ************************* ENCODER VALUES ******************************
 ***********************************************************************/
// TURRET ROTATE
// TODO: get these values
// The farthest the turret can rotate positive or negative
#define MAX_TURRET_ROTATE_EV 5850

// TURRET HOOD
// If above this, we can freely rotate past the interference point
#define HOOD_INTERFERENCE_EV 310
// Highest the hood can go
#define MAX_HOOD_HEIGHT_EV 2000

// DRIVETRAIN
//go forward this much on one side and reverse the same amount on the other for a 90 degree turn.
//TODO: update this once the robot is finalized.
// mm/deg
#define DISTANCE_PER_DEGREE_EV (745.0/90.0)
// mm/tick
#define DISTANCE_PER_PULSE_EV

// INTAKE HEIGHT
// Zeroes at top
#define BALL_HEIGHT_EV 12032
#define FLOOR_HEIGHT_EV 2343423423423432


#endif
