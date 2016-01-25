#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DrivetrainSub* CommandBase::rDrivetrainSub = NULL;
IntakeSub* CommandBase::rIntakeSub = NULL;
ShooterSub* CommandBase::rShooterSub = NULL;
CameraSub* CommandBase::rCameraSub = NULL;
HopperSub* CommandBase::rHopperSub = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	rDrivetrainSub = new DrivetrainSub(LeftDrive1PWM, LeftDrive2PWM, RightDrive1PWM, RightDrive2PWM, LeftDriveEncoder1DIO, LeftDriveEncoder2DIO,
			RightDriveEncoder1DIO, RightDriveEncoder2DIO);
	rIntakeSub = new IntakeSub(IntakePWM, IntakeLimitDIO);
	rShooterSub = new ShooterSub(ShooterMotorPWM, ShooterEncoder1DIO, ShooterEncoder2DIO);
	rCameraSub = new CameraSub();
	rHopperSub = new HopperSub(HopperPWM, HopperLimitDIO);
	//OI must be at the bottom!!
	oi = new OI();
}
