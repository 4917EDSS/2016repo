#include "DriveStraightCmd.h"

DriveStraightCmd::DriveStraightCmd()
{
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
	rDrivetrainSub->Drive(0.5, 0.5);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	if (rDrivetrainSub->GetLeftEnc() >= 3000){
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{
	rDrivetrainSub->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{
	rDrivetrainSub->Drive(0, 0);
}
