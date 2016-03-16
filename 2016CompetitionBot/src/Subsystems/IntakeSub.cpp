#include "IntakeSub.h"
#include "../Commands/ControlIntakeWithJoystickCmd.h"
#include "../RobotMap.h"

IntakeSub::IntakeSub() :
		Subsystem("IntakeSub")
{
	intakeMotor = new Talon(IntakePWM);
	adjustMotor = new Talon(AdjustPWM);
	heightEncoder = new Encoder(HeightEncoder1DIO, HeightEncoder2DIO);
	intakeUpLimit = new DigitalInput(IntakeUpLimitDIO);

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

void IntakeSub::SetHeight(int height){
	targetHeight = height;
}

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

void IntakeSub::Update(){
	if (GetRawHeight() > targetHeight + INTAKE_HEIGHT_TARGET_RANGE){
		SetVerticalSpeed(-0.4);
	}
	else if (GetRawHeight() < targetHeight - INTAKE_HEIGHT_TARGET_RANGE){
		SetVerticalSpeed(0.4);
	}
	else {
		SetVerticalSpeed(0.0);
	}
}

bool IntakeSub::IsOnTarget() {
	return GetRawHeight() >= targetHeight - INTAKE_HEIGHT_TARGET_RANGE && GetRawHeight() <= targetHeight + INTAKE_HEIGHT_TARGET_RANGE;
}

void IntakeSub::SetVerticalSpeed(float speed)
{
	if(GetIntakeUp())
	{
		heightEncoder->Reset();
		if (speed < 0){
			adjustMotor->Set(0.0);
			return;
		}

	}
	else if (GetRawHeight() >= BOTTOM_INTAKE_HEIGHT_EV - INTAKE_HEIGHT_TARGET_RANGE && speed > 0){
		adjustMotor->Set(0.0);
		return;
	}

	adjustMotor->Set(speed);
}

void IntakeSub::SetIntakeSpeed(float speed)
{
	intakeMotor->Set(-speed);
}
