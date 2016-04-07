#include "SetHoodHeightCmd.h"

SetHoodHeightCmd::SetHoodHeightCmd(int height) : height(height), exitWhenAtTarget(true)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(rHoodSub);
}

SetHoodHeightCmd::SetHoodHeightCmd(int height, bool exitAtTarget) : height(height), exitWhenAtTarget(exitAtTarget)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(rHoodSub);
}

// Called just before this Command runs the first time
void SetHoodHeightCmd::Initialize()
{
	rHoodSub->SetTiltHeight(height);
}

// Called repeatedly when this Command is scheduled to run
void SetHoodHeightCmd::Execute()
{
	rHoodSub->Update(false);
}

// Make this return true when this Command no longer needs to run execute()
bool SetHoodHeightCmd::IsFinished()
{
	return exitWhenAtTarget && rHoodSub->IsOnTarget();
}

// Called once after isFinished returns true
void SetHoodHeightCmd::End()
{
	rHoodSub->SetTurretTilt(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetHoodHeightCmd::Interrupted()
{
	End();
}
