#include "DrivetrainSub.h"
#include "../RobotMap.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DSubsystem")
{
	leftMotor = new Talon(LEFT_MOTOR_PWM_PORT);
	rightMotor = new Talon(RIGHT_MOTOR_PWM_PORT);
}

void DrivetrainSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DrivetrainSub::Drive(float leftSpeed, float rightSpeed)
{
	leftMotor->Set(leftSpeed);
	rightMotor->Set(rightSpeed);
}
