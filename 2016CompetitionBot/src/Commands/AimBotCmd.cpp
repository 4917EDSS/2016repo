#include "AimBotCmd.h"
#include "RobotMap.h"

AimBotCmd::AimBotCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(rShooterSub);
}

// Called just before this Command runs the first time
void AimBotCmd::Initialize()
{




}

// Called repeatedly when this Command is scheduled to run
void AimBotCmd::Execute()
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
bool AimBotCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AimBotCmd::End()
{
	rShooterSub->SetTurretRotate(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimBotCmd::Interrupted()
{
	End();
}
