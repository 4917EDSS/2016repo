//COMMAND NOT IMPLEMENTED YET, WAITING ON DETAILS ABOUT ROBOT
#include "LowBarTransformCmd.h"

LowBarTransformCmd::LowBarTransformCmd()
{
	Requires(rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LowBarTransformCmd::Initialize()
{
	rShooterSub->SetTurretTilt(1.0);
}

// Called repeatedly when this Command is scheduled to run
void LowBarTransformCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowBarTransformCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LowBarTransformCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowBarTransformCmd::Interrupted()
{

}
