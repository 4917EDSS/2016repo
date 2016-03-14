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
		float rightStick = oi->DGetRightVer(DRIVE_SENSITIVITY);
		float leftStick = oi->DGetLeftVer(DRIVE_SENSITIVITY);
		if (rightStick > 0) {
			rightStick = rightStick * 0.85 + 0.15;
		}
		else if (rightStick < 0) {
			rightStick = rightStick * 0.85 - 0.15;
		}
		if (leftStick > 0) {
			leftStick = leftStick * 0.85 + 0.15;
		}
		else if (leftStick < 0) {
			leftStick = leftStick * 0.85 - 0.15;
		}
		rDrivetrainSub->Drive(leftStick, rightStick);
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
