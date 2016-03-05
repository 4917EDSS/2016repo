#include "BallToIntakeCmd.h"
#include "Timer.h"

BallToIntakeCmd::BallToIntakeCmd()
{
	Requires(rHopperSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BallToIntakeCmd::Initialize()
{

	rHopperSub->SetHopperMotorOut(1.0);
}

// Called repeatedly when this Command is scheduled to run
void BallToIntakeCmd::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool BallToIntakeCmd::IsFinished()
{

	return TimeSinceInitialized() > 1.75;
}

// Called once after isFinished returns true
void BallToIntakeCmd::End()
{
	rHopperSub->SetHopperMotorOut(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallToIntakeCmd::Interrupted()
{
	End();
}
