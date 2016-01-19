#include "IdleCmd.h"

IdleCmd::IdleCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void IdleCmd::Initialize()
{
	drivetrainSub->Drive(0.0, 0.0);
}

// Called repeatedly when this Command is scheduled to run
void IdleCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IdleCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IdleCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IdleCmd::Interrupted()
{

}
