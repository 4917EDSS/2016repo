#include "SpinupCmd.h"
#include <iostream>

SpinupCmd::SpinupCmd()
{
	Requires(rShooterSub);

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SpinupCmd::Initialize()
{
	rShooterSub->Spin(1.0);
}

// Called repeatedly when this Command is scheduled to run
void SpinupCmd::Execute()
{
	//The plan is to have a sensor in the hopper for when a ball is there. Only run the ShooterMotor when there is a ball there.
}

// Make this return true when this Command no longer needs to run execute()
bool SpinupCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SpinupCmd::End()
{
	rShooterSub->Spin(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinupCmd::Interrupted()
{
	End();
}
