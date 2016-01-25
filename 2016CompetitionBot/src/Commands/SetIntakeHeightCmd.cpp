#include "SetIntakeHeightCmd.h"

SetIntakeHeightCmd::SetIntakeHeightCmd(int destination)
{
	isUp = true;
	height = destination;
	Requires(rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetIntakeHeightCmd::Initialize()
{
	if (rIntakeSub->GetHeight() > height)
		{
			rIntakeSub->SetVerticalSpeed(0.5);
			isUp = true;
		}
		else
		{
			rIntakeSub->SetVerticalSpeed(-0.5);
			isUp = false;
		}

}

// Called repeatedly when this Command is scheduled to run
void SetIntakeHeightCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetIntakeHeightCmd::IsFinished()
{
	if (isUp){
		if (rIntakeSub->GetHeight() > height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (rIntakeSub->GetHeight() < height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
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

}
