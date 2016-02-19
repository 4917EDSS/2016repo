#include "ResetDrivetrainEncCmd.h"

ResetDrivetrainEncCmd::ResetDrivetrainEncCmd()
{
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ResetDrivetrainEncCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
}

// Called repeatedly when this Command is scheduled to run
void ResetDrivetrainEncCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetDrivetrainEncCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetDrivetrainEncCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetDrivetrainEncCmd::Interrupted()
{

}
