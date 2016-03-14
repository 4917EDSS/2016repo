#include "ShooterSub.h"
#include "../Commands/ControlTurretWithJoystickCmd.h"
#include <cfloat>
#include "../RobotMap.h"
#include "../Components/Encoder4917.h"

ShooterSub::ShooterSub() :
		Subsystem("ExampleSubsystem")
{
x = 0;


	spinnerMotor = new CANTalon(ShooterMotorCAN);
	spinnerMotor->SetControlMode(CANSpeedController::ControlMode::kVoltage);
	spinnerMotor->SetPID(FLYWHEEL_P, FLYWHEEL_I, FLYWHEEL_D);
	spinnerMotor->EnableControl();
	rotateTurretMotor = new Talon(TurretRotatePWM);

	shooterEncoder = new Encoder4917(ShooterEncoder1DIO, ShooterEncoder2DIO);
	rotateEncoder = new Encoder(RotateTurretEncoder1DIO, RotateTurretEncoder2DIO);

	turretCentered = new DigitalInput(TurretCenteredLimitDIO);

	sideOfShooter = RIGHT_OF_ZERO;
	maxRightEnc = -FLT_MAX;
	maxRightOffset = -FLT_MAX;
	minLeftEnc = FLT_MAX;
	minLeftOffset = FLT_MAX;



	LiveWindow::GetInstance()->AddActuator("Shooter", "spinnerMotor", spinnerMotor);
	LiveWindow::GetInstance()->AddActuator("Shooter", "rotateMotor", rotateTurretMotor);
	LiveWindow::GetInstance()->AddSensor("Shooter", "rotateEncoder", rotateEncoder);
	LiveWindow::GetInstance()->AddSensor("Shooter", "turretCentered", turretCentered);



	rotateSetpoint = 0;

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

	if (GetRawRotateEnc() < -MAX_TURRET_ROTATE_EV && speed > 0) {
		// Hard stop on the RIGHT
		rotateTurretMotor->Set(0.0);
	}
	else if (GetRawRotateEnc() > MAX_TURRET_ROTATE_EV && speed < 0) {
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
	return linearRotation - centerX;
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
	rotateSetpoint = newTarget;
}

bool ShooterSub::IsOnTarget() {
	return GetRawRotateEnc() >= -ROTATE_MARGIN + rotateSetpoint && GetRawRotateEnc() <= ROTATE_MARGIN + rotateSetpoint;
}

void ShooterSub::Update(bool visionActive){
	if(visionActive)
	{
		float offset = GetTargetOffsetFromCenter();

		if (!CommandBase::rDrivetrainSub->GetTryingToDrive() || !CommandBase::rDrivetrainSub->GetAHRS()->IsMoving()) {
			// We consider this not moving
			if (sideOfShooter == RIGHT_OF_ZERO) {
				// Started on the right side
				if (minLeftEnc > GetRawRotateEnc()) {
					minLeftEnc = GetRawRotateEnc();
				}
				if (minLeftOffset > offset) {
					minLeftOffset = offset;
				}
				if (rotateEncoder->GetRate() > 0) {
					if (maxRightEnc < GetRawRotateEnc()) {
						maxRightEnc = GetRawRotateEnc();
					}
					if (maxRightOffset < offset) {
						maxRightOffset = offset;
					}
				} else if (rotateEncoder->GetRate() < 0 && maxRightEnc > -FLT_MAX && minLeftEnc < FLT_MAX) {
					if (maxRightOffset < offset) {
						maxRightOffset = offset;
					}
					// minLeftOffset should be negative, maxRightOffset should be positive
					// Weighting the each side by the amount the camera is off to the opposite side
					// So, if our camera is way off left (offset -10, 2), and our encoder vals are (100, 1000)
					// then our center is (2*100 + 10*1000)/(10+2) = 10200/12 = 850, so we will go to 850
					centerEnc = (maxRightEnc*fabs(minLeftOffset) + minLeftEnc*maxRightOffset) / (maxRightOffset + fabs(minLeftOffset));
				}
			} else {
				// Started on the left side
				if (maxRightEnc < GetRawRotateEnc()) {
					maxRightEnc = GetRawRotateEnc();
				}
				if (maxRightOffset < offset) {
					maxRightOffset = offset;
				}
				if (rotateEncoder->GetRate() < 0) {
					if (minLeftEnc > GetRawRotateEnc()) {
						minLeftEnc = GetRawRotateEnc();
					}
					if (minLeftOffset > offset) {
						minLeftOffset = offset;
					}
				} else if (rotateEncoder->GetRate() > 0 && maxRightEnc > -FLT_MAX && minLeftEnc < FLT_MAX) {
					if (minLeftOffset > offset) {
						minLeftOffset = offset;
					}
					// minLeftOffset should be negative, maxRightOffset should be positive
					// Weighting the each side by the amount the camera is off to the opposite side
					// So, if our camera is way off left (offset -10, 2), and our encoder vals are (100, 1000)
					// then our center is (2*100 + 10*1000)/(10+2) = 10200/12 = 850
					centerEnc = (maxRightEnc*fabs(minLeftOffset) + minLeftEnc*maxRightOffset) / (maxRightOffset + fabs(minLeftOffset));
				}
			}
		}
		else {
			ResetAutoShot();
		}
		if (centerEnc == FLT_MAX) {
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
		} else {
			SetTarget(centerEnc);
			RotateWithEncoder();
		}
	}
	else
	{
		RotateWithEncoder();
	}

}

void ShooterSub::ResetAutoShot() {
	sideOfShooter = GetTargetOffsetFromCenter() > 0 ? RIGHT_OF_ZERO : LEFT_OF_ZERO;
	maxRightEnc = -FLT_MAX;
	centerEnc = FLT_MAX;
	minLeftEnc = FLT_MAX;
	maxRightOffset = -FLT_MAX;
	minLeftOffset = FLT_MAX;
}

void ShooterSub::RotateWithEncoder() {
	if(rotateSetpoint > GetRawRotateEnc()+ROTATE_MARGIN)
	{
		RotateTurretClockwise(0.4);
	}
	else if(rotateSetpoint < GetRawRotateEnc()-ROTATE_MARGIN)
	{
		RotateTurretCounterClockwise(0.4);
	}
	else {
		SetTurretRotate(0.0);
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
