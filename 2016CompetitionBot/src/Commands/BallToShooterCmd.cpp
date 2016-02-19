#include "BallToShooterCmd.h"
#include "Timer.h"

BallToShooterCmd::BallToShooterCmd()
{
	Requires(rHopperSub);
	Requires(rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BallToShooterCmd::Initialize()
{
	rHopperSub->SetHopperMotorIn(1.0);
	rShooterSub->Spin(1.0);
}

// Called repeatedly when this Command is scheduled to run
void BallToShooterCmd::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool BallToShooterCmd::IsFinished()
{
	return TimeSinceInitialized() > 1.0;
}

// Called once after isFinished returns true
void BallToShooterCmd::End()
{
	rHopperSub->SetHopperMotorIn(0.0);
	rShooterSub->Spin(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallToShooterCmd::Interrupted()
{
	End();
}
