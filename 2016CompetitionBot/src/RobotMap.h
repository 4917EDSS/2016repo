#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/***********************************************************************
 ********************** roboRIO I/O Port Map ***************************
 ***********************************************************************/

// Note that in addition to the labeled ports on the roboRIO, the MXP (myRIO Expansion Port)
// supports additional functionality.
//  - 4 analog inputs
//  - 2 analog outputs
//  - +5V
//  - +3.3V
//  - a total of 16 DIOs, all pins have dual functionality, DIO and
//     - 10 PWMs (10 pins)
//     - I2C (2 pins)
//     - SPI (4 pins)
//  - a UART
//  - digital ground


// PWM (Pulse-Width Modulation) Outputs
#define LeftDrive1PWM	0
#define RightDrive1PWM	1
//#define free			2
//#define free			3
#define IntakePWM 		4   //Actually intaking or expelling boulders by rotating the intake drums.
#define ExtensionMotorPWM	5 // For the climbing mechanism
#define AdjustPWM 		6 	//Moves the intake subsystem.
#define HopperPWM 		7   //Moves boulder from hopper to SpinnerMotor.
#define TurretRotatePWM 8	//Rotates shooting turret(Yaw).
#define TurretTiltPWM 	9   //Tilts shooting turret(Pitch).

// DIOs (Digital Inputs/Outputs)
// on roboRIO
#define HopperLimitDIO			0
#define HeightEncoder1DIO		1  //These are for the height of the intake.
#define HeightEncoder2DIO		2
#define TurretCenteredLimitDIO	3
#define TiltDownDIO				4
#define IntakeUpLimitDIO		5
#define RotateTurretEncoder1DIO 6
#define RotateTurretEncoder2DIO 7
#define TiltEncoder1DIO 		8
#define TiltEncoder2DIO 		9

// on MXP (myRIO Expansion Port) via NavX-MXP expansion board
#define ShooterEncoder1DIO 		10
#define ShooterEncoder2DIO 		11
#define LeftDriveEncoder2DIO 	12
#define LeftDriveEncoder1DIO 	13
//#define free
#define RightDriveEncoder1DIO 	18
#define RightDriveEncoder2DIO 	19

// CAN (Controller Area Network) Bus
#define ShooterMotorCAN			0	//High speed wheels to launch the boulder.

// I2C (Inter-Integrated Circuit) Bus
//#define free

// RS-232 (serial) Port
//#define free

// SPI (Serial Peripheral Interface) with 4 Slave-Select Lines
//#define free			0
//#define free			1
//#define free			2
//#define free			3

// Analog Inputs
//#define free			0	// Note:  Some of these inputs might be buggy
//#define free			1
//#define free			2
//#define free			3

// Relay FWD and REV Outputs
//#define free			0
//#define free			1
//#define free			2
//#define free			3

// USB Ports
// Two available

// PNC (Pneumatics Control Module) Outputs
#define ShifterSolenoid1PNC 	0
#define ShifterSolenoid2PNC 	1


/***********************************************************************
 *************************** SUBSYSTEMS ********************************
 ***********************************************************************/
//////////////////////// Machine Vision Camera Subsystem ////////////////////////
#define MIDDLE_CAMERA_X 120.0
#define TARGET_RANGE 0.5


//////////////////////// Live-view Camera Subsystem ////////////////////////
#define CAMERA_NAME "cam2"


//////////////////////// Drivetrain Subsystem ////////////////////////
#define TANK_DRIVE_CONTROLS 1
#define FPS_DRIVE_CONTROLS 2
#define AHRSInterface SPI::kMXP

#define DRIVE_BALANCE_P 0.04
#define DRIVE_BALANCE_I 0
#define DRIVE_BALANCE_D 0
#define DRIVE_BALANCE_TOLERANCE 0.01

#define DRIVE_TURN_P 0.075
#define DRIVE_TURN_I 0
#define DRIVE_TURN_D 0.0268
#define DRIVE_TURN_TOLERANCE 0.2

#define TURNING_TOLERANCE 0.5 //In degress
#define TURNING_TOLERANCE_DURATION 0.45 //In seconds, must be in tolerance this long

#define ACCELERATION_THRESHOLD 0.1
#define DRIVE_SENSITIVITY 2.0      //The higher the number, the less sensitive.

//Some bool constants used for code readability
#define IS_DRIVE true
#define IS_SHIFTER false

//go forward this much on one side and reverse the same amount on the other for a 90 degree turn.
//TODO: update this once the robot is finalized.
// mm/deg
#define DISTANCE_PER_DEGREE_EV (745.0/90.0)
// mm/tick
#define DISTANCE_PER_PULSE_EV (5000.0/29100.0)

#define ENCODER_CONVERSION_FACTOR 4


//////////////////////// Hopper Subsystem ////////////////////////
#define BALL_TO_SHOOTER_TIME 2.5

//////////////////////// Intake Subsystem ////////////////////////
// Zeroes at top
#define BOTTOM_INTAKE_HEIGHT_EV 225
#define INTAKE_HEIGHT_TARGET_RANGE 3
//Auto defense crossing heights
#define LOW_BAR_INTAKE_HEIGHT_EV 125
#define SIMPLE_DEFENSE_INTAKE_HEIGHT_EV 75

#define NUM_CYCLES_INTAKE_STALL 20


//////////////////////// Shooter Subsystem ////////////////////////
#define ROTATE_MARGIN 10
#define ROTATE_SLOW 0.25
#define ROTATE_BASE_SPEED 0.4
#define ROTATE_SPEED_FACTOR 3000

#define FRONT_TOUCHING_BATTER_EV 733
#define RESTING_ON_BACK_BATTER_EV 475

#define AUTO_SHOT_OFFSET_LEFT 50

#define FLYWHEEL_P 10
#define FLYWHEEL_I 1
#define FLYWHEEL_D 0
#define FLYWHEEL_VOLTAGE 11.2

#define LEFT_OF_ZERO false
#define RIGHT_OF_ZERO true

//Vision Adjustment Values
#define ADJUSTMENT_P 0.02
#define ADJUSTMENT_F 0.23
#define ADJUST_MAX_SPEED 0.5

// TURRET ROTATE
// TODO: get these values
// The farthest the turret can rotate positive or negative
#define MAX_TURRET_ROTATE_EV 5715


#define RIGHT_SIDE -1
#define LEFT_SIDE 1

// TURRET HOOD
// Highest the hood can go
#define MAX_HOOD_HEIGHT_EV 3800
//Range for target height of hood
#define HOOD_HEIGHT_TARGET_RANGE 40
#define TILT_SLOW 0.3

#define SLOW_DOWN_TILT_ENC_RANGE 500
#define MAX_TILT_AUTO_SPEED 0.6
#define MIN_TILT_AUTO_SPEED 0.1

#define BATTER_WALL_HOOD_HEIGHT 1500
#define BATTER_WALL_TURRET_ENC_LEFT 5400
#define BATTER_WALL_TURRET_ENC_RIGHT (-5400)

//////////////////////// Vision Math Constants /////////////////////
//Distance
#define DISTANCE_EQUATION_QA 0.000082410 //Old: 0.00010046 //OLDer: 0.00008217
#define DISTANCE_EQUATION_QB 0.005409 //Old: -0.00026929 //OLDer: 0.00161487
#define DISTANCE_EQUATION_QC 1.318080 //Old: 1.39859538 //OLDer: 1.34776440
//Rotation
#define ROTATION_EQUATION_LM 8.963565 //Old: 6.8503 //OLDer: 5.7811
#define ROTATION_EQUATION_LB 73.949064 //Adjusted LB becaues of bracket mounted to the left  Old: 77.349 //OLDer: 58.443

//Tilt Height
#define HEIGHT_EQUATION_QA -161.052143 // OLD:-213.724
#define HEIGHT_EQUATION_QB 1041.246165  // OLD: 1561.49
#define HEIGHT_EQUATION_QC -43.805191 // OLD: (-410.8)


/***********************************************************************
 *************************** Autonomous ********************************
 ***********************************************************************/
//Distances in mm. Negative for reverse.
#define CROSS_BASIC_DEFENSE_DISTANCE 3300
#define CROSS_LOW_BAR_SLOW_DISTANCE -3000
#define CROSS_LOW_BAR_FAST_DISTANCE -1750
#define POSITION_ONE_APPROACH_DISTANCE 1600
#define POSITION_TWO_APPROACH_DISTANCE 2300
#define POSITION_TWO_LEFT_APPROACH_DISTANCE 3000
#define POSITION_THREE_APPROACH_DISTANCE 1750
#define POSITION_THREE_RIGHT_APPROACH_DISTANCE 3750
#define POSITION_FOUR_APPROACH_DISTANCE 2000
#define POSITION_FIVE_APPROACH_DISTANCE 2700

//Speeds
#define CROSS_FAST_DEFENSE_SPEED 0.8
#define CROSS_BASIC_DEFENSE_SPEED 0.6
#define LOW_BAR_DEFENSE_SPEED 0.5

//Degree of Turns. Negative for Counterclockwise, Positive for Clockwise.
#define LOW_BAR_TURN_TO_SHOOT -125
#define POSITION_TWO_TURN_TO_SHOOT 60
#define POSITION_TWO_LEFT_TURN_TO_SHOOT 30
#define POSITION_TWO_LEFT_TURN_TO_DEFENCE -30
#define POSITION_THREE_TURN_TO_SHOOT 30
#define POSITION_THREE_RIGHT_TURN_TO_APPROACH 40
#define POSITION_THREE_RIGHT_TURN_TO_SHOOT -100
#define POSITION_FOUR_TURN_TO_SHOOT -5
#define POSITION_FIVE_TURN_TO_SHOOT -30
#define LOW_BAR_TURN_TO_DEFENCE 125
#define POSITION_TWO_TURN_TO_DEFENCE 120
#define POSITION_THREE_TURN_TO_DEFENCE 150
#define POSITION_FOUR_TURN_TO_DEFENCE 5
#define POSITION_FIVE_TURN_TO_DEFENCE 30
//Time
#define AIM_TIME_AUTO 2//seconds

//Hood Heights
#define POSITION_ONE_HOOD_HEIGHT 1500
#define POSITION_TWO_HOOD_HEIGHT 1500
#define POSITION_THREE_HOOD_HEIGHT 1600
#define POSITION_FOUR_HOOD_HEIGHT 1500
#define POSITION_FIVE_HOOD_HEIGHT 1650


#endif

