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

float HoodSub::GetGripValue(std::string gripValue)
{
	int TargetIndex = 0, widestTarget = 0;

	std::shared_ptr<NetworkTable> gripTable = NetworkTable::GetTable("GRIP/myContoursReport");

	std::vector<double> WidthArray = gripTable->GetNumberArray("width", llvm::ArrayRef<double>());

	if (WidthArray.size() < 1)
	{
		return 0.0;
	}

	for (unsigned int i = 0; i < WidthArray.size(); i++) {
		if (WidthArray[i] > widestTarget)
		{
			TargetIndex = i;
			widestTarget = WidthArray[i];
		}
	}

	std::vector<double> ValuesArray = gripTable->GetNumberArray(gripValue, llvm::ArrayRef<double>());

	return ValuesArray[TargetIndex];
}

float HoodSub::GetTargetDistance(){
	float centerY = GetGripValue("centerY");

	float quadraticDistance = DISTANCE_EQUATION_QA*centerY*centerY + DISTANCE_EQUATION_QB*centerY + DISTANCE_EQUATION_QC;
	std::cout << "centerY" << centerY << std::endl;
	std::cout << "Quadratic Distance " << quadraticDistance << " m" << std::endl;
	return quadraticDistance;
}

int HoodSub::GetVisionHeight(){
	float computedHeight = HEIGHT_EQUATION_QA*GetTargetDistance()*GetTargetDistance() + HEIGHT_EQUATION_QB*GetTargetDistance() + HEIGHT_EQUATION_QC;
	return int(computedHeight);
}

void HoodSub::Update(bool VisionActive) {
	if (VisionActive){
		SetTiltHeight(GetVisionHeight());
		if (GetRawTiltEnc() > HOOD_HEIGHT_TARGET_RANGE + targetHeight){
			tiltTurretMotor->Set(-0.4);
		}
		else if (GetRawTiltEnc() < -HOOD_HEIGHT_TARGET_RANGE + targetHeight){
			tiltTurretMotor->Set(0.4);
		}
		else {
			tiltTurretMotor->Set(0.0);
		}
	}
	else{
		if (GetRawTiltEnc() > HOOD_HEIGHT_TARGET_RANGE + targetHeight){
			tiltTurretMotor->Set(-0.4);
		}
		else if (GetRawTiltEnc() < -HOOD_HEIGHT_TARGET_RANGE + targetHeight){
			tiltTurretMotor->Set(0.4);
		}
		else {
			tiltTurretMotor->Set(0.0);
		}
	}
}

bool HoodSub::IsOnTarget() {
	return GetRawTiltEnc() >= -HOOD_HEIGHT_TARGET_RANGE + targetHeight && GetRawTiltEnc() <= HOOD_HEIGHT_TARGET_RANGE + targetHeight;
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
