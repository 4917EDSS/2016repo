#include "HopperSub.h"
#include "../RobotMap.h"

HopperSub::HopperSub(int hopperMotorC, int ballInLimitC) :
		Subsystem("HopperSub")
{
	hopperMotor = new Talon(hopperMotorC);
	ballInLimit = new DigitalInput(ballInLimitC);
}

void HopperSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
bool HopperSub::IsBallIn()
{
	return ballInLimit->Get();
}

void HopperSub::SetHopperMotorIn(float speed)
{
	hopperMotor->Set(speed);
}

void HopperSub::SetHopperMotorOut(float speed)
{
	hopperMotor->Set(-speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
