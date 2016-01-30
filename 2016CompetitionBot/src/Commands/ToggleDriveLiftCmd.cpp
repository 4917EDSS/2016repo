#include "ToggleDriveLiftCmd.h"

ToggleDriveLiftCmd::ToggleDriveLiftCmd()
{
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleDriveLiftCmd::Initialize()
{
	rDrivetrainSub->SetLiftShift(!rDrivetrainSub->GetLiftShift());
}

// Called repeatedly when this Command is scheduled to run
void ToggleDriveLiftCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleDriveLiftCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleDriveLiftCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleDriveLiftCmd::Interrupted()
{

}
