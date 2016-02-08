#include "FireCmd.h"

FireCmd::FireCmd()
{
	Requires(rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void FireCmd::Initialize()
{

	rShooterSub->Spin(1.0);
}

// Called repeatedly when this Command is scheduled to run
void FireCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool FireCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FireCmd::End()
{
	rShooterSub->Spin(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireCmd::Interrupted()
{
	End();
}
