#include "IntakeSub.h"
#include "../RobotMap.h"

IntakeSub::IntakeSub(int intakeMotorC, int ballHitLimitC) :
		Subsystem("IntakeSub")
{
	intakeMotor = new Talon(intakeMotorC);
	ballHitLimit = new DigitalInput(ballHitLimitC);
}


void IntakeSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
bool IntakeSub::IsBallLoaded()
{
	return !ballHitLimit->Get();
}

void IntakeSub::SetIntakeSpeed(float speed)
{
	intakeMotor->Set(speed);
}
