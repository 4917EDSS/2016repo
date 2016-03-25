#include "ClimberSub.h"
#include "../RobotMap.h"

ClimberSub::ClimberSub() :
		Subsystem("ExampleSubsystem")
{
	ExtensionMotor = new Talon(ExtensionMotorPWM);
}

void ClimberSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void ClimberSub::SetExtenderSpeed(float speed)
{
	ExtensionMotor->Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
