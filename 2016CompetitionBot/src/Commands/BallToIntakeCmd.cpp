#include "BallToIntakeCmd.h"

BallToIntakeCmd::BallToIntakeCmd()
{
	timer = 0;
	Requires(rHopperSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BallToIntakeCmd::Initialize()
{
	timer = 0;
	rHopperSub->SetHopperMotor(1);
}

// Called repeatedly when this Command is scheduled to run
void BallToIntakeCmd::Execute()
{
	timer++;
}

// Make this return true when this Command no longer needs to run execute()
bool BallToIntakeCmd::IsFinished()
{
	return timer>100;
}

// Called once after isFinished returns true
void BallToIntakeCmd::End()
{
	rHopperSub->SetHopperMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallToIntakeCmd::Interrupted()
{
	End();
}
