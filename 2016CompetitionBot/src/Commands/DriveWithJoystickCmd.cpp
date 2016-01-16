#include "DriveWithJoystickCmd.h"
#include "CommandBase.h"
#include "RobotMap.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	Requires(rDrivetrainSub.get());
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
		rDrivetrainSub->Drive(oi->DGetLeftVer(), oi->DGetRightVer());
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
	}
	else
	{
		rDrivetrainSub->Drive(oi->DGetLeftVer() - oi->DGetLeftHor(), oi->DGetRightVer() + oi->DGetLeftHor());
		SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
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
