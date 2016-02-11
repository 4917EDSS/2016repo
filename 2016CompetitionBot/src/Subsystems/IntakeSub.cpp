#include "IntakeSub.h"
#include "../Commands/ControlIntakeWithJoystickCmd.h"
#include "../RobotMap.h"

IntakeSub::IntakeSub(int intakeMotorC, int adjustMotorC, int heightEncoder1C, int heightEncoder2C, int intakeUpLimitC) :
		Subsystem("IntakeSub")
{
	intakeMotor = new Talon(intakeMotorC);
	adjustMotor = new Talon(adjustMotorC);
	heightEncoder = new Encoder(heightEncoder1C, heightEncoder2C);
	intakeUpLimit = new DigitalInput(intakeUpLimitC);
}


void IntakeSub::InitDefaultCommand()
{
	SetDefaultCommand(new ControlIntakeWithJoystickCmd());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
int IntakeSub::GetHeight()
{
	return (int) heightEncoder->GetDistance();
}

bool IntakeSub::GetIntakeUp(){
	return intakeUpLimit->Get();
}

int IntakeSub::GetRawHeight()
{
	return (int) heightEncoder->GetRaw();
}

void IntakeSub::SetVerticalSpeed(float speed)
{
	if(GetIntakeUp())
	{
		heightEncoder->Reset();
	}
	adjustMotor->Set(speed);
}

void IntakeSub::SetIntakeSpeed(float speed)
{
	intakeMotor->Set(speed);
}
