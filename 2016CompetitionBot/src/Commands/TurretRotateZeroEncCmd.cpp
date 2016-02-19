#include "TurretRotateZeroEncCmd.h"
#include "RobotMap.h"

TurretRotateZeroEncCmd::TurretRotateZeroEncCmd()
{
	Requires(rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void TurretRotateZeroEncCmd::Initialize()
{
	rShooterSub->SetTarget(0);
}

// Called repeatedly when this Command is scheduled to run
void TurretRotateZeroEncCmd::Execute()
{
	rShooterSub->Update(false);
}

// Make this return true when this Command no longer needs to run execute()
bool TurretRotateZeroEncCmd::IsFinished()
{
	return rShooterSub->GetRotateEnc() < ROTATE_MARGIN && rShooterSub->GetRotateEnc() > -ROTATE_MARGIN;
}

// Called once after isFinished returns true
void TurretRotateZeroEncCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurretRotateZeroEncCmd::Interrupted()
{

}
