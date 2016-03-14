#include "ZeroRotateEncoderCmd.h"

ZeroRotateEncoderCmd::ZeroRotateEncoderCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(rShooterSub);
}

// Called just before this Command runs the first time
void ZeroRotateEncoderCmd::Initialize()
{
	rShooterSub->ResetRotate();
}

// Called repeatedly when this Command is scheduled to run
void ZeroRotateEncoderCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ZeroRotateEncoderCmd::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ZeroRotateEncoderCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroRotateEncoderCmd::Interrupted()
{

}
