#include "HoodSub.h"
#include "../Commands/ControlHoodWithJoystickCmd.h"
#include "../RobotMap.h"

HoodSub::HoodSub() :
		Subsystem("ExampleSubsystem")
{
	tiltTurretMotor = new Talon(TurretTiltPWM);
	tiltTurretMotor->SetInverted(true); // tilt motor up = positive speed, wiring doesn't match this
	tiltEncoder = new Encoder(TiltEncoder1DIO, TiltEncoder2DIO);
	tiltDown = new DigitalInput(TiltDownDIO);
	LiveWindow::GetInstance()->AddActuator("Shooter", "tiltMotor", tiltTurretMotor);
	LiveWindow::GetInstance()->AddSensor("Shooter", "tiltEncoder", tiltEncoder);
	LiveWindow::GetInstance()->AddSensor("Shooter", "tiltDown", tiltDown);

}

//The reset function only works if SetTurretTilt is constantly called.
void HoodSub::SetTurretTilt(float speed)
{
	if (GetTiltDown())
	{
		tiltEncoder->Reset();
		if (speed < 0) {
			tiltTurretMotor->Set(0.0);

			return;
		}
	}
	if (GetRawTiltEnc() >= MAX_HOOD_HEIGHT_EV && speed > 0) {
		//Stop tilting if at max height
		tiltTurretMotor->Set(0.0);
	}
	else {
		tiltTurretMotor->Set(speed);
	}
}

void HoodSub::SetTiltHeight(int height){
	targetHeight = height;
}

int HoodSub::GetVisionHeight(){
	float dist = CommandBase::GetTargetDistance();
	float computedHeight = HEIGHT_EQUATION_QA*dist*dist + HEIGHT_EQUATION_QB*dist + HEIGHT_EQUATION_QC;
	return int(computedHeight);
}

void HoodSub::Update(bool VisionActive) {
	if (VisionActive){
		SetTiltHeight(GetVisionHeight());
	}
	if (GetRawTiltEnc() > targetHeight + HOOD_HEIGHT_TARGET_RANGE){
		tiltTurretMotor->Set(-0.4);
	}
	else if (GetRawTiltEnc() < targetHeight - HOOD_HEIGHT_TARGET_RANGE){
		tiltTurretMotor->Set(0.4);
	}
	else {
		tiltTurretMotor->Set(0.0);
	}
}

bool HoodSub::IsOnTarget() {
	return GetRawTiltEnc() >= targetHeight - HOOD_HEIGHT_TARGET_RANGE && GetRawTiltEnc() <= targetHeight + HOOD_HEIGHT_TARGET_RANGE;
}

float HoodSub::GetRawTiltEnc() {
	return tiltEncoder->GetRaw();
}

float HoodSub::GetTiltEnc() {
	return tiltEncoder->GetDistance();
}

void HoodSub::ResetTiltEnc(){
	tiltEncoder->Reset();
}

bool HoodSub::GetTiltDown(){
	return tiltDown->Get();
}

void HoodSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlHoodWithJoystickCmd());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
