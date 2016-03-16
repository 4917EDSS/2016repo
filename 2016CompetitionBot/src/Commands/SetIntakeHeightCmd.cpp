#include "SetIntakeHeightCmd.h"

SetIntakeHeightCmd::SetIntakeHeightCmd(int height) : height(height)
{

	Requires(rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetIntakeHeightCmd::Initialize()
{
	rIntakeSub->SetHeight(height);

}

// Called repeatedly when this Command is scheduled to run
void SetIntakeHeightCmd::Execute()
{
	rIntakeSub->Update();
}

// Make this return true when this Command no longer needs to run execute()
bool SetIntakeHeightCmd::IsFinished()
{
	return rIntakeSub->IsOnTarget();
}

// Called once after isFinished returns true
void SetIntakeHeightCmd::End()
{
	rIntakeSub->SetVerticalSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetIntakeHeightCmd::Interrupted()
{
	End();
}
