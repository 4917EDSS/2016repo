#include "ControlHopperWithJoystickCmd.h"

ControlHopperWithJoystickCmd::ControlHopperWithJoystickCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(rHopperSub);
}

// Called just before this Command runs the first time
void ControlHopperWithJoystickCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlHopperWithJoystickCmd::Execute()
{
	rHopperSub->SetHopperMotorIn(-oi->OGetRightVer(2.0));
}

// Make this return true when this Command no longer needs to run execute()
bool ControlHopperWithJoystickCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlHopperWithJoystickCmd::End()
{
	rHopperSub->SetHopperMotorIn(0.0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlHopperWithJoystickCmd::Interrupted()
{
	End();
}
