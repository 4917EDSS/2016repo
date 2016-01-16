#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/DrivetrainSub.h"
#include "Commands/Scheduler.h"

//Talons
#define LeftDrive1PWM 0
#define LeftDrive2PWM 2
#define RightDrive1PWM 1
#define RightDrive2PWM 3

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
	static std::unique_ptr<DrivetrainSub> rDrivetrainSub;
	static std::unique_ptr<OI> oi;
};

#endif
