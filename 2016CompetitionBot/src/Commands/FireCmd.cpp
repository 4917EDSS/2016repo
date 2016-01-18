#include "FireCmd.h"

FireCmd::FireCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void FireCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FireCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool FireCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FireCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireCmd::Interrupted()
{

}
