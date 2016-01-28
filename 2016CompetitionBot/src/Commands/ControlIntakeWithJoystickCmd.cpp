#include "ControlIntakeWithJoystickCmd.h"
#include "OI.h"

ControlIntakeWithJoystickCmd::ControlIntakeWithJoystickCmd()
{
	Requires(rIntakeSub);
	//Requires(rHopperSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ControlIntakeWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlIntakeWithJoystickCmd::Execute()
{
	if ((oi->OGetRightVer() != 0.0) && (rHopperSub->IsBallIn()))
			{
				rIntakeSub->SetIntakeSpeed(oi->OGetRightVer());
			}
	else
	{
		rIntakeSub->SetIntakeSpeed(0.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlIntakeWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlIntakeWithJoystickCmd::End()
{
	rIntakeSub->SetIntakeSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlIntakeWithJoystickCmd::Interrupted()
{
	End();
}
