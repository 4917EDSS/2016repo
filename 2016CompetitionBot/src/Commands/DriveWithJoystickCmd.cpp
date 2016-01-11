#include "DriveWithJoystickCmd.h"
#include "CommandBase.h"
#include "RobotMap.h"

DriveWithJoystickCmd::DriveWithJoystickCmd()
{
	previousRightSpeed = 0;
	previousLeftSpeed = 0;
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
			if (oi->DGetLeftVer() - previousLeftSpeed > rDrivetrainSub->GetAccelThresh())
			{
				previousLeftSpeed += rDrivetrainSub->GetAccelThresh();
			}
			else if (oi->DGetLeftVer()-previousLeftSpeed < -rDrivetrainSub->GetAccelThresh())
			{
				previousLeftSpeed -= rDrivetrainSub->GetAccelThresh();
			}
			else
			{
				previousLeftSpeed = oi->DGetLeftVer();
			}

			if (oi->DGetRightVer()-previousRightSpeed > rDrivetrainSub->GetAccelThresh())
			{
				previousRightSpeed += rDrivetrainSub->GetAccelThresh();
			}
			else if (oi->DGetRightVer()-previousRightSpeed < -rDrivetrainSub->GetAccelThresh())
			{
				previousRightSpeed -= rDrivetrainSub->GetAccelThresh();
			}
			else
			{
				previousRightSpeed = oi->DGetRightVer();
			}


			rDrivetrainSub->Drive(oi->DGetLeftVer(), oi->DGetRightVer());
			SmartDashboard::PutNumber("leftStickValue", oi->DGetLeftVer());
		}

		else
		{
			if (oi->DGetLeftVer()-previousLeftSpeed > rDrivetrainSub->GetAccelThresh())
			{
				previousLeftSpeed += rDrivetrainSub->GetAccelThresh();
			}
			else if (oi->DGetLeftVer()-previousLeftSpeed < -rDrivetrainSub->GetAccelThresh())
			{
				previousLeftSpeed -= rDrivetrainSub->GetAccelThresh();
			}
			else
			{
				previousLeftSpeed = oi->DGetLeftVer();
			}
			if (oi->DGetRightHor()-previousRightSpeed > rDrivetrainSub->GetAccelThresh())
			{
				previousRightSpeed += rDrivetrainSub->GetAccelThresh();
			}
			else if (oi->DGetRightHor()-previousRightSpeed < -rDrivetrainSub->GetAccelThresh())
			{
				previousRightSpeed -= rDrivetrainSub->GetAccelThresh();
			}
			else
			{
				previousRightSpeed = oi->DGetRightHor();
			}

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
