#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

#define TANK_DRIVE_CONTROLS 1
#define FPS_DRIVE_CONTROLS 2

#define ACCELERATION_THRESHOLD 0.1

//go forward this much on one side and reverse the same amount on the other for a 90 degree turn.
//TODO: update this once the robot is finalized.
#define DISTANCE_PER_DEGREE (745.0/90.0)


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
