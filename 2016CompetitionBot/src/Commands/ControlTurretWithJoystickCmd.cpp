#include "ControlTurretWithJoystickCmd.h"
#include "OI.h"
#include "RobotMap.h"

ControlTurretWithJoystickCmd::ControlTurretWithJoystickCmd()
{
	Requires(rShooterSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ControlTurretWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlTurretWithJoystickCmd::Execute()
{
	//Tilting the turret with the left joystick vertical axis
	rShooterSub->SetTurretTilt(oi->OGetLeftVer(2.0));

	//Turning the turret with the left operator joystick horizontal axis
	if (oi->OGetLeftHor(2.0) != 0.0)
	{
		rShooterSub->SetTurretRotate(-oi->OGetLeftHor(2.0));
	}


}

// Make this return true when this Command no longer needs to run execute()
bool ControlTurretWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlTurretWithJoystickCmd::End()
{
	rShooterSub->SetTurretRotate(0.0);
	rShooterSub->SetTurretTilt(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlTurretWithJoystickCmd::Interrupted()
{
	End();
}
