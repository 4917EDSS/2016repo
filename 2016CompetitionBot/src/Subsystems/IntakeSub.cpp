#include "IntakeSub.h"
#include "../RobotMap.h"

IntakeSub::IntakeSub(int intakeMotorC, int adjustMotorC, int heightEncoder1C, int heightEncoder2C) :
		Subsystem("IntakeSub")
{
	intakeMotor = new Talon(intakeMotorC);
	adjustMotor = new Talon(adjustMotorC);
	heightEncoder = new Encoder(heightEncoder1C, heightEncoder2C);
}


void IntakeSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
int IntakeSub::GetHeight()
{
	return (int) heightEncoder->GetDistance();
}

int IntakeSub::GetRawHeight()
{
	return (int) heightEncoder->GetRaw();
}

void IntakeSub::SetVerticalSpeed(float speed)
{
	adjustMotor->Set(speed);
}

void IntakeSub::SetIntakeSpeed(float speed)
{
	intakeMotor->Set(speed);
}
