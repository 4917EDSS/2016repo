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
//#define free			5
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
#define RotateTurretEncoder2DIO 6
#define RotateTurretEncoder1DIO 7
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
#define DRIVE_TURN_D 0.3
#define DRIVE_TURN_TOLERANCE 0.0268

#define ACCELERATION_THRESHOLD 0.1
#define DRIVE_SENSITIVITY 0.7      //The higher the number, the less sensitive.

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
#define BALL_HEIGHT_EV 12032
#define FLOOR_HEIGHT_EV 2343423423423432


//////////////////////// Shooter Subsystem ////////////////////////
#define ROTATE_MARGIN 10
#define ROTATE_SLOW 0.25

#define FRONT_TOUCHING_BATTER_EV 733
#define RESTING_ON_BACK_BATTER_EV 475

#define FLYWHEEL_P 10
#define FLYWHEEL_I 1
#define FLYWHEEL_D 0
#define FLYWHEEL_VOLTAGE 11.2
//Vision Adjustment Values
#define ADJUSTMENT_P 0.02
#define ADJUSTMENT_F 0.2
#define ADJUST_MAX_SPEED 0.5

// TURRET ROTATE
// TODO: get these values
// The farthest the turret can rotate positive or negative
#define MAX_TURRET_ROTATE_EV 5600

// TURRET HOOD
// Highest the hood can go
#define MAX_HOOD_HEIGHT_EV 3800
//Range for target height of hood
#define HOOD_HEIGHT_TARGET_RANGE 50

//////////////////////// Vision Math Constants /////////////////////
//Distance
#define DISTANCE_EQUATION_QA 0.0000643248
#define DISTANCE_EQUATION_QB 0.00315265
#define DISTANCE_EQUATION_QC 1.18675
//Rotation
#define ROTATION_EQUATION_LM 8.26
#define ROTATION_EQUATION_LB 80.396


#endif

