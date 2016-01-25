#include "IntakeUntilLimitHitCmd.h"

IntakeUntilLimitHitCmd::IntakeUntilLimitHitCmd()
{
	Requires(rIntakeSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void IntakeUntilLimitHitCmd::Initialize()
{
	rIntakeSub->SetIntakeSpeed(1.0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeUntilLimitHitCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeUntilLimitHitCmd::IsFinished()
{
	//return rIntakeSub->IsBallLoaded();
	return true;
}

// Called once after isFinished returns true
void IntakeUntilLimitHitCmd::End()
{
	rIntakeSub->SetIntakeSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeUntilLimitHitCmd::Interrupted()
{
	End();
}
