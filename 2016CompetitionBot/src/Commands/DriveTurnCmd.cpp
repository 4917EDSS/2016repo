#include "DriveTurnCmd.h"
#include "RobotMap.h"

DriveTurnCmd::DriveTurnCmd(int turnDegrees, bool isClockwiseTurnParam, float driveSpeedParam)
{
	driveSpeed = fabs(driveSpeedParam);
	isClockwiseTurn = isClockwiseTurnParam;
	turnEncoderValues = turnDegrees * DISTANCE_PER_DEGREE;
	previousLeftEncoder = 0;
	previousRightEncoder = 0;
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveTurnCmd::Initialize()
{
	if (isClockwiseTurn)
	{
		rDrivetrainSub->Drive(driveSpeed, -driveSpeed);

	}
	else
	{
		rDrivetrainSub->Drive(-driveSpeed, driveSpeed);
	}

	rDrivetrainSub->ResetDrive();
}

// Called repeatedly when this Command is scheduled to run
void DriveTurnCmd::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished()
{


	if ((rDrivetrainSub->GetLeftEnc() <= turnEncoderValues) && (rDrivetrainSub->GetRightEnc() >= turnEncoderValues)) {
		return true;
	} else {
		return false;
	}

}

// Called once after isFinished returns true
void DriveTurnCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurnCmd::Interrupted()
{

}
