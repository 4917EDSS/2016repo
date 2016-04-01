#include "ControlIntakeWithJoystickCmd.h"
#include "OI.h"

ControlIntakeWithJoystickCmd::ControlIntakeWithJoystickCmd()
{
	Requires(rIntakeSub);
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
	// Dealing with height of intake
	if (oi->OGetPov() == 315 || oi->OGetPov() == 0 || oi->OGetPov() == 45) {
		rIntakeSub->SetVerticalSpeed(-0.7);
	}
	else if (oi->OGetPov() <= 230 && oi->OGetPov() >= 130 ) {
		rIntakeSub->SetVerticalSpeed(0.7);
	}
	else {
		rIntakeSub->SetVerticalSpeed(0.0);
	}
	// Dealing with intake in and out motors
	rIntakeSub->SetIntakeSpeed(oi->OGetRightVer(2.0));
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
	rIntakeSub->SetVerticalSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlIntakeWithJoystickCmd::Interrupted()
{
	End();
}
