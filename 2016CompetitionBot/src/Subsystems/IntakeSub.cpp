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

	LiveWindow::GetInstance()->AddActuator("Intake", "intakeMotor", intakeMotor);
	LiveWindow::GetInstance()->AddActuator("Intake", "adjustMotor", adjustMotor);
	LiveWindow::GetInstance()->AddSensor("Intake", "heightEncoder", heightEncoder);
	LiveWindow::GetInstance()->AddSensor("Intake", "intakeUpLimit", intakeUpLimit);
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

int IntakeSub::GetRawHeight()
{
	return (int) heightEncoder->GetRaw();
}

bool IntakeSub::GetIntakeUp(){
	return !intakeUpLimit->Get();
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
	intakeMotor->Set(-speed);
}
