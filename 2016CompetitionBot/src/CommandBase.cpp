#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DrivetrainSub* CommandBase::rDrivetrainSub = NULL;
IntakeSub* CommandBase::rIntakeSub = NULL;
HoodSub* CommandBase::rHoodSub = NULL;
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
	rDrivetrainSub = new DrivetrainSub();
	rIntakeSub = new IntakeSub();
	rHoodSub = new HoodSub();
	rShooterSub = new ShooterSub();
	//rCameraSub = new CameraSub(); commented out to allow for better console outputs
	rHopperSub = new HopperSub();

	//OI must be at the bottom!!
	oi = new OI();
}
