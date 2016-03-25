#include "RetractClimberCmd.h"

RetractClimberCmd::RetractClimberCmd()
{
	Requires(rClimberSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void RetractClimberCmd::Initialize()
{
	rClimberSub->SetExtenderSpeed(-1.0);
}

// Called repeatedly when this Command is scheduled to run
void RetractClimberCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool RetractClimberCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RetractClimberCmd::End()
{
	rClimberSub->SetExtenderSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RetractClimberCmd::Interrupted()
{
	End();
}
