#include "ControlHoodWithJoystickCmd.h"
#include "OI.h"

ControlHoodWithJoystickCmd::ControlHoodWithJoystickCmd()
{
	Requires(rHoodSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ControlHoodWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlHoodWithJoystickCmd::Execute()
{
	//Tilting the turret with the left joystick vertical axis
	rHoodSub->SetTurretTilt(oi->OGetLeftVer(2.0));
}

// Make this return true when this Command no longer needs to run execute()
bool ControlHoodWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlHoodWithJoystickCmd::End()
{
	rHoodSub->SetTurretTilt(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlHoodWithJoystickCmd::Interrupted()
{
	End();
}
