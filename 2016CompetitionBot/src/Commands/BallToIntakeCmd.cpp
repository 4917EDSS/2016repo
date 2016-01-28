#include "BallToIntakeCmd.h"
#include "Timer.h"

BallToIntakeCmd::BallToIntakeCmd()
{
	timerOne = new Timer();
	timer = 0;

	Requires(rHopperSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BallToIntakeCmd::Initialize()
{
	std::string error_string = "I like me";
	DriverStation::ReportError(error_string.c_str());
	timerOne->Start();
	timerOne->Reset();
	timer = 0;

	rHopperSub->SetHopperMotor(1.0);
}

// Called repeatedly when this Command is scheduled to run
void BallToIntakeCmd::Execute()
{
	timer ++;
}

// Make this return true when this Command no longer needs to run execute()
bool BallToIntakeCmd::IsFinished()
{

	return (timer > 100) ? true : false;
}

// Called once after isFinished returns true
void BallToIntakeCmd::End()
{
	rHopperSub->SetHopperMotor(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallToIntakeCmd::Interrupted()
{
	End();
}
