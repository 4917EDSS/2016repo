#include "ShooterSub.h"
#include "../Commands/ControlTurretWithJoystickCmd.h"
#include "../RobotMap.h"
#include "../Components/Encoder4917.h"

ShooterSub::ShooterSub(int shooterMotorC, int shooterEncoder1C, int shooterEncoder2C, int tiltEncoder1C, int tiltEncoder2C, int rotateEncoder1C, int rotateEncoder2C, int turretRotateC, int turretTiltC, int turretCenteredC) :
		Subsystem("ExampleSubsystem")
{
	spinnerMotor = new Talon(shooterMotorC);
	rotateTurretMotor = new Talon(turretRotateC);
	tiltTurretMotor = new Talon(turretTiltC);

	shooterEncoder = new Encoder4917(shooterEncoder1C, shooterEncoder2C);
	tiltEncoder = new Encoder(tiltEncoder1C, tiltEncoder2C);
	rotateEncoder = new Encoder(rotateEncoder1C, rotateEncoder2C);

	turretCentered = new DigitalInput(turretCenteredC);

	target = 0;

}


void ShooterSub::Spin(float spinSpeed)
{
	spinnerMotor->Set(spinSpeed);
}

void ShooterSub::SetTurretRotate(float speed)
{
	rotateTurretMotor->Set(speed);
}

void ShooterSub::SetTurretTilt(float speed)
{
	tiltTurretMotor->Set(speed);
}

float ShooterSub::GetTargetOffsetFromCenter()
{
	int TargetIndex = 0, temp = 0;
	float  TargetWidth = 0;

	std::shared_ptr<NetworkTable> gripTable = NetworkTable::GetTable("GRIP/myContoursReport");

	std::vector<double> WidthArray = gripTable->GetNumberArray("width", llvm::ArrayRef<double>());

	if (WidthArray.size() < 1)
	{
		return 0.0;
	}

	for (unsigned int i = 0; i < WidthArray.size(); i++) {
		if (WidthArray[i] > temp)
		{
			temp = i;
		}
	}

	TargetIndex = temp;

	std::vector<double> XArray = gripTable->GetNumberArray("centerX", llvm::ArrayRef<double>());

	TargetWidth = XArray[TargetIndex] - MIDDLE_CAMERA_X;
	return TargetWidth;
}

float ShooterSub::GetTiltEnc() {
	return tiltEncoder->GetDistance();
}

float ShooterSub::GetRotateEnc(){
	return rotateEncoder->GetDistance();
}

bool ShooterSub::GetTurretCentered(){
	return turretCentered->Get();
}

void ShooterSub::SetTarget(int newTarget){
	target = newTarget;
}

void ShooterSub::Update(bool visionActive){
	if(GetTurretCentered())
	{
		rotateEncoder->Reset();
	}
	if(visionActive)
	{
		if (GetTargetOffsetFromCenter() > TARGET_RANGE)
		{
			SetTurretRotate(1.0);
		}
		else if (GetTargetOffsetFromCenter() < -TARGET_RANGE)
		{
			SetTurretRotate(-1.0);
		}
		else
		{
			SetTurretRotate(0.0);
		}
	}
	else
	{
		if(target > GetRotateEnc()+ROTATE_MARGIN)
		{
			SetTurretRotate(1.0);
		}
		else if(target < GetRotateEnc()-ROTATE_MARGIN)
		{
			SetTurretRotate(-1.0);
		}
	}

}

void ShooterSub::InitDefaultCommand()
{
	SetDefaultCommand(new ControlTurretWithJoystickCmd());
	//SetDefaultCommand(new AimBotCmd());
	//SetDefaultCommand(new SpinupCmd());

	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
