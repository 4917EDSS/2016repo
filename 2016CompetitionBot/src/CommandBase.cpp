#include "CommandBase.h"
#include "Subsystems/DrivetrainSub.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DrivetrainSub> CommandBase::rDrivetrainSub;

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
	rDrivetrainSub.reset(new DrivetrainSub(LeftDrive1PWM, LeftDrive2PWM, RightDrive1PWM, RightDrive2PWM));

	oi.reset(new OI());
}
