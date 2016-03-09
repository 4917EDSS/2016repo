#include "ShooterSub.h"
#include "../Commands/ControlTurretWithJoystickCmd.h"
#include "../RobotMap.h"
#include "../Components/Encoder4917.h"

ShooterSub::ShooterSub() :
		Subsystem("ExampleSubsystem")
{
	spinnerMotor = new CANTalon(ShooterMotorCAN);
	spinnerMotor->SetControlMode(CANSpeedController::ControlMode::kVoltage);
	spinnerMotor->SetPID(FLYWHEEL_P, FLYWHEEL_I, FLYWHEEL_D);
	spinnerMotor->EnableControl();
	rotateTurretMotor = new Talon(TurretRotatePWM);

	shooterEncoder = new Encoder4917(ShooterEncoder1DIO, ShooterEncoder2DIO);
	rotateEncoder = new Encoder(RotateTurretEncoder1DIO, RotateTurretEncoder2DIO);

	turretCentered = new DigitalInput(TurretCenteredLimitDIO);

	LiveWindow::GetInstance()->AddActuator("Shooter", "spinnerMotor", spinnerMotor);
	LiveWindow::GetInstance()->AddActuator("Shooter", "rotateMotor", rotateTurretMotor);
	LiveWindow::GetInstance()->AddSensor("Shooter", "rotateEncoder", rotateEncoder);
	LiveWindow::GetInstance()->AddSensor("Shooter", "turretCentered", turretCentered);



	target = 0;

}


void ShooterSub::Spin(float spinSpeed)
{
	spinnerMotor->Set(spinSpeed*FLYWHEEL_VOLTAGE);
}


void ShooterSub::RotateTurretClockwise(float speed) {
	SetTurretRotate(-speed);
}

void ShooterSub::RotateTurretCounterClockwise(float speed) {
	SetTurretRotate(speed);
}

//The reset function only works if SetTurretRotate is constantly called.
void ShooterSub::SetTurretRotate(float speed)
{
	speed *= ROTATE_SLOW;
	if (GetTurretCentered())
	{
		rotateEncoder->Reset();
	}

	if (GetRawRotateEnc() < -MAX_TURRET_ROTATE_EV && speed < 0) {
		// Hard stop on the RIGHT
		rotateTurretMotor->Set(0.0);
	}
	else if (GetRawRotateEnc() > MAX_TURRET_ROTATE_EV && speed > 0) {
		// Hard stop on the LEFT
		rotateTurretMotor->Set(0.0);
	}
	else {
		rotateTurretMotor->Set(speed);
	}
}




float ShooterSub::GetTargetOffsetFromCenter(){

	float centerX = CommandBase::GetGripValue("centerX");
	if (centerX < 1) {
		return 0.0;
	}

	float linearRotation = ROTATION_EQUATION_LM*CommandBase::GetTargetDistance() + ROTATION_EQUATION_LB;
	std::cout << "Difference " << linearRotation - centerX << " pixels" << std::endl;
	return linearRotation - centerX;
}

float ShooterSub::GetRotateEnc(){
	return rotateEncoder->GetDistance();
}

float ShooterSub::GetRawRotateEnc(){
	return rotateEncoder->GetRaw();
}

bool ShooterSub::GetTurretCentered(){
	return false;//turretCentered->Get();
}

void ShooterSub::ResetRotate() {
	rotateEncoder->Reset();
}

void ShooterSub::SetTarget(int newTarget){
	target = newTarget;
}

bool ShooterSub::IsOnTarget() {
	return GetRawRotateEnc() >= -ROTATE_MARGIN + target && GetRawRotateEnc() <= ROTATE_MARGIN + target;
}

void ShooterSub::Update(bool visionActive){
	if(visionActive)
	{
		float offset = GetTargetOffsetFromCenter();
		std::cout << "OFFSET " << offset << std::endl;
		if (offset > TARGET_RANGE)
		{
			RotateTurretCounterClockwise(std::min(fabs(offset)*ADJUSTMENT_P+ADJUSTMENT_F, ADJUST_MAX_SPEED));
		}
		else if (offset < -TARGET_RANGE)
		{
			RotateTurretClockwise(std::min(fabs(offset)*ADJUSTMENT_P+ADJUSTMENT_F, ADJUST_MAX_SPEED));
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
			RotateTurretCounterClockwise(0.4);
		}
		else if(target < GetRotateEnc()-ROTATE_MARGIN)
		{
			RotateTurretClockwise(0.4);
		}
		else {
			SetTurretRotate(0.0);
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
