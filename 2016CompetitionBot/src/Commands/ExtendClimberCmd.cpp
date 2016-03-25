#include "ExtendClimberCmd.h"

ExtendClimberCmd::ExtendClimberCmd()
{
	Requires(rClimberSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ExtendClimberCmd::Initialize()
{
	rClimberSub->SetExtenderSpeed(1.0);
}

// Called repeatedly when this Command is scheduled to run
void ExtendClimberCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ExtendClimberCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ExtendClimberCmd::End()
{
	rClimberSub->SetExtenderSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExtendClimberCmd::Interrupted()
{
	End();
}
