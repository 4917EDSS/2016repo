#include "BallToShooterCmd.h"
#include "Timer.h"

BallToShooterCmd::BallToShooterCmd()
{
	timerOne = new Timer;
	timer = 0;


	Requires(rHopperSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BallToShooterCmd::Initialize()
{
	timerOne->Start();
	timerOne->Reset();
	timer = 0;

	rHopperSub->SetHopperMotorIn(1.0);
}

// Called repeatedly when this Command is scheduled to run
void BallToShooterCmd::Execute()
{
	timer ++;

}

// Make this return true when this Command no longer needs to run execute()
bool BallToShooterCmd::IsFinished()
{

	return (timer > 100) ? true : false;
}

// Called once after isFinished returns true
void BallToShooterCmd::End()
{
	rHopperSub->SetHopperMotorIn(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallToShooterCmd::Interrupted()
{
	End();
}
