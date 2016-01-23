#include "CameraUpdateCmd.h"

CameraUpdateCmd::CameraUpdateCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(rCameraSub);
	prevTime = 0;
}

// Called just before this Command runs the first time
void CameraUpdateCmd::Initialize()
{

	rCameraSub->StartFeed();

}

// Called repeatedly when this Command is scheduled to run
void CameraUpdateCmd::Execute()
{
	// ~15fps
	if (TimeSinceInitialized() - prevTime > 66.6)
	{
		rCameraSub->RunFeed();
		prevTime = TimeSinceInitialized();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CameraUpdateCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CameraUpdateCmd::End()
{
	rCameraSub->EndFeed();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraUpdateCmd::Interrupted()
{
	End();
}
