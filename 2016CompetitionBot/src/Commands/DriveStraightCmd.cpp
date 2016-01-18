#include "DriveStraightCmd.h"

DriveStraightCmd::DriveStraightCmd()

{
	time = 100000;
#pragma message("The following line doesn't build.  Fix it and then delete this line.")
//	Requires(rDrivetrainSub->get()); // TODO: Fix me /////////////////////////////////////////////////////////////////
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize()
{
	rDrivetrainSub->Drive(0.5, 0.5);


}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	if (time == 0) {
			return true;
		} else {
			return true;
			time ++;
		}
}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{

}
