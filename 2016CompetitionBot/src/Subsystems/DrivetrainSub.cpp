#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"

DrivetrainSub::DrivetrainSub(int leftMotor1C, int leftMotor2C, int rightMotor1C, int rightMotor2C) :
		Subsystem("DrivetrainSub")
{
	leftMotor1.reset(new Talon(leftMotor1C));
	leftMotor2.reset(new Talon(leftMotor2C));
	rightMotor1.reset(new Talon(rightMotor1C));
	rightMotor2.reset(new Talon(rightMotor2C));

	controlState = TANK_DRIVE_CONTROLS;
	accelThreshold = ACCELERATION_THRESHOLD;



}

void DrivetrainSub::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystickCmd());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DrivetrainSub::Drive(float leftSpeed, float rightSpeed)
{
	leftMotor1->Set(leftSpeed);
	leftMotor2->Set(leftSpeed);
	rightMotor1->Set(rightSpeed);
	rightMotor2->Set(leftSpeed);

}

void DrivetrainSub::ToggleControls(){
	if(controlState == FPS_DRIVE_CONTROLS){
		controlState = TANK_DRIVE_CONTROLS;
	}
	else{
		controlState = FPS_DRIVE_CONTROLS;
	}
}
int DrivetrainSub::GetControls()
{
	return controlState;
}

float DrivetrainSub::GetAccelThresh()
{
	return accelThreshold;
}

void DrivetrainSub::SetAccelThresh(float accelThresh)
{
	accelThreshold = accelThresh;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
