#include "ReverseFlywheelCmd.h"

ReverseFlywheelCmd::ReverseFlywheelCmd()
{
	Requires(rShooterSub);
	Requires(rHopperSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ReverseFlywheelCmd::Initialize()
{
	rShooterSub->Spin(-1.0);
	rHopperSub->SetHopperMotorOut(1.0);
}

// Called repeatedly when this Command is scheduled to run
void ReverseFlywheelCmd::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ReverseFlywheelCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ReverseFlywheelCmd::End()
{
	rShooterSub->Spin(0.0);
	rHopperSub->SetHopperMotorOut(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseFlywheelCmd::Interrupted()
{
	End();
}
