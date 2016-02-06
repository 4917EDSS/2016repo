#include "PrepareShotCmd.h"
#include "RobotMap.h"

PrepareShotCmd::PrepareShotCmd()
{
	Requires (rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void PrepareShotCmd::Initialize()
{
	rShooterSub->Spin(1.0);
}

// Called repeatedly when this Command is scheduled to run
void PrepareShotCmd::Execute()
{
	if (rShooterSub->GetTargetOffsetFromCenter() > TARGET_RANGE)
		{
			rShooterSub->SetTurretRotate(1.0);
		}
		else if (rShooterSub->GetTargetOffsetFromCenter() < -TARGET_RANGE)
		{
			rShooterSub->SetTurretRotate(-1.0);
		}
		else
		{
			rShooterSub->SetTurretRotate(0.0);
		}
}

// Make this return true when this Command no longer needs to run execute()
bool PrepareShotCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PrepareShotCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrepareShotCmd::Interrupted()
{

}
