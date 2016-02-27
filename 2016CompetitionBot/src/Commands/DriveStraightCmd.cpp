#include "DriveStraightCmd.h"
#include "RobotMap.h"
#include <iostream>

DriveStraightCmd::DriveStraightCmd(int distance, float speed)
{
	targetSpeed = speed;
	targetDistance = distance;
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveStraightCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
	rDrivetrainSub->EnableBalancerPID(0);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightCmd::Execute()
{
	if (targetDistance > 0) {
		rDrivetrainSub->PIDDrive(targetSpeed);
	} else if (targetDistance < 0) {
		rDrivetrainSub->PIDDrive(-targetSpeed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightCmd::IsFinished()
{
	if (abs(rDrivetrainSub->GetLeftEnc()) >= abs(targetDistance)){
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveStraightCmd::End()
{
	rDrivetrainSub->DisableBalancerPID();
	rDrivetrainSub->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightCmd::Interrupted()
{
	End();
}
