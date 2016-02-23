#include <cmath>
#include "DriveWithJoystickCmd.h"
#include "CommandBase.h"
#include "RobotMap.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystickCmd::Execute()
{
	if(rDrivetrainSub->GetControls() == TANK_DRIVE_CONTROLS)
	{
		rDrivetrainSub->Drive(oi->DGetLeftVer(DRIVE_SENSITIVITY), oi->DGetRightVer(DRIVE_SENSITIVITY));
	}
	else
	{
		rDrivetrainSub->Drive(oi->DGetLeftVer(DRIVE_SENSITIVITY) - oi->DGetRightHor(DRIVE_SENSITIVITY), oi->DGetLeftVer(DRIVE_SENSITIVITY) + oi->DGetRightHor(DRIVE_SENSITIVITY));
	}

}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystickCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystickCmd::Interrupted()
{

}
