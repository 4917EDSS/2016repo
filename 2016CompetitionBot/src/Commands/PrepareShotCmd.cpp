#include "PrepareShotCmd.h"
#include "RobotMap.h"
#include <iostream>

PrepareShotCmd::PrepareShotCmd()
{
	Requires (rShooterSub);
	Requires (rHoodSub);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void PrepareShotCmd::Initialize()
{
	rShooterSub->Spin(1.0);
	rShooterSub->ResetAutoShot();
}

// Called repeatedly when this Command is scheduled to run
void PrepareShotCmd::Execute()
{
	rShooterSub->Update(true);
	rHoodSub->Update(true);
	//std::cout << rShooterSub->spinnerMotor->GetOutputCurrent() << " is Current" << std::endl;
	//std::cout << rShooterSub->spinnerMotor->GetOutputVoltage() << " is Voltage" << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool PrepareShotCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PrepareShotCmd::End()
{
	rShooterSub->SetTurretRotate(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrepareShotCmd::Interrupted()
{
	End();
}
