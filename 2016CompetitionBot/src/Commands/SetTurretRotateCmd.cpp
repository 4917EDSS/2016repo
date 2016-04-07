#include "SetTurretRotateCmd.h"

SetTurretRotateCmd::SetTurretRotateCmd(int rotate): rotate(rotate), spinUp(false)
{
	Requires(rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

SetTurretRotateCmd::SetTurretRotateCmd(int rotate, bool spinup): rotate(rotate), spinUp(spinup)
{
	Requires(rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetTurretRotateCmd::Initialize()
{
	rShooterSub->SetTarget(rotate);
	if (spinUp) {
		rShooterSub->Spin(1.0);
	}
}

// Called repeatedly when this Command is scheduled to run
void SetTurretRotateCmd::Execute()
{
	rShooterSub->Update(false);
}

// Make this return true when this Command no longer needs to run execute()
bool SetTurretRotateCmd::IsFinished()
{
	if (spinUp) {
		return false;
	}
	return rShooterSub->IsOnTarget();
}

// Called once after isFinished returns true
void SetTurretRotateCmd::End()
{
	if (spinUp) {
		rShooterSub->Spin(0.0);
	}
	rShooterSub->RotateTurretClockwise(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetTurretRotateCmd::Interrupted()
{
	End();
}
