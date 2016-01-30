#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/DrivetrainSub.h"
#include "Subsystems/IntakeSub.h"
#include "Subsystems/ShooterSub.h"
#include "Subsystems/CameraSub.h"
#include "Subsystems/HopperSub.h"
#include "Commands/Scheduler.h"

//Talons
#define LeftDrive1PWM 0
#define LeftDrive2PWM 2
#define RightDrive1PWM 1
#define RightDrive2PWM 3
#define IntakePWM 4       //Actually intaking or expelling boulders by rotating the intake drums.
#define ShooterMotorPWM 5 //High speed wheels to launch the boulder.
#define AdjustPWM 6 	  //Moves the intake subsystem.
#define HopperPWM 7       //Moves boulder from hopper to SpinnerMotor.
#define TurretRotatePWM 8    //Rotates shooting turret(Yaw).
#define TurretTiltPWM 9      //Tilts shooting turret(Pitch).


//Digital Input/Output
#define HopperLimitDIO 0
#define HeightEncoder1DIO 1
#define HeightEncoder2DIO 2
#define ShooterEncoder1DIO 8
#define ShooterEncoder2DIO 9
#define LeftDriveEncoder1DIO 6
#define LeftDriveEncoder2DIO 7
#define RightDriveEncoder1DIO 4
#define RightDriveEncoder2DIO 5


//Air Outputs
#define ShifterSolenoid1PNC 0
#define ShifterSolenoid2PNC 1

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DrivetrainSub* rDrivetrainSub;
	static IntakeSub* rIntakeSub;
	static ShooterSub* rShooterSub;
	static CameraSub* rCameraSub;
	static HopperSub* rHopperSub;
	// OI MUST BE AT BOTTOM
	static OI* oi;
};

#endif
