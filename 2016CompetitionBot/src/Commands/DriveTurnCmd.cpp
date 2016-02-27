#include "DriveTurnCmd.h"
#include "RobotMap.h"

DriveTurnCmd::DriveTurnCmd(float turnDegrees, float driveSpeedParam) : turnDegrees(turnDegrees)
{
	driveSpeed = fabs(driveSpeedParam);
	Requires(rDrivetrainSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveTurnCmd::Initialize()
{
	rDrivetrainSub->ResetDrive();
	rDrivetrainSub->EnableTurnPID(turnDegrees);
}

// Called repeatedly when this Command is scheduled to run
void DriveTurnCmd::Execute()
{
	rDrivetrainSub->PIDTurn();

}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished()
{
	if (rDrivetrainSub->IsTurnFinished()){
		return true;
	} else {
		return false;
	}

}

// Called once after isFinished returns true
void DriveTurnCmd::End()
{
	rDrivetrainSub->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurnCmd::Interrupted()
{
	End();
}
