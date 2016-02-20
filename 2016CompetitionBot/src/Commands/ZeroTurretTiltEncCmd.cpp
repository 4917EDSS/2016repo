#include "ZeroTurretTiltEncCmd.h"

ZeroTurretTiltEncCmd::ZeroTurretTiltEncCmd()
{
	Requires(rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ZeroTurretTiltEncCmd::Initialize()
{
	rShooterSub->SetTurretTilt(-1.0);
}

// Called repeatedly when this Command is scheduled to run
void ZeroTurretTiltEncCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ZeroTurretTiltEncCmd::IsFinished()
{
	return rShooterSub->GetTiltDown();
}

// Called once after isFinished returns true
void ZeroTurretTiltEncCmd::End()
{
	rShooterSub->SetTurretTilt(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroTurretTiltEncCmd::Interrupted()
{
	End();
}
