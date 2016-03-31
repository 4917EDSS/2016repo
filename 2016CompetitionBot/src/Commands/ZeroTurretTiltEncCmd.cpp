#include "ZeroTurretTiltEncCmd.h"

ZeroTurretTiltEncCmd::ZeroTurretTiltEncCmd()
{
	Requires(rHoodSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ZeroTurretTiltEncCmd::Initialize()
{
	rHoodSub->SetTurretTilt(-0.4);
}

// Called repeatedly when this Command is scheduled to run
void ZeroTurretTiltEncCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ZeroTurretTiltEncCmd::IsFinished()
{
	return rHoodSub->GetTiltDown();
}

// Called once after isFinished returns true
void ZeroTurretTiltEncCmd::End()
{
	rHoodSub->SetTurretTilt(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroTurretTiltEncCmd::Interrupted()
{
	End();
}
