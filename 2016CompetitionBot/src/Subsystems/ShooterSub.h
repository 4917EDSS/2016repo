#ifndef ShooterSub_H
#define ShooterSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Components/Encoder4917.h"

class ShooterSub: public Subsystem
{
private:
	Talon* spinnerMotor;
	Talon* rotateTurretMotor;
	Talon* tiltTurretMotor;
	Encoder4917* shooterEncoder;
	Encoder* tiltEncoder;
	DigitalInput* tiltDown;
	Encoder* rotateEncoder;
	DigitalInput* turretCentered;
	int target;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterSub(int shooterMotorC, int shooterEncoder1C, int shooterEncoder2C, int tiltEncoder1C, int tiltEncoder2C, int rotateEncoder1C, int rotateEncoder2C, int turretRotateC, int turretTiltC, int tiltDownC, int turrentCenteredC);
	void Spin(float spinSpeed);
	void SetTurretTilt(float speed);
	float GetTargetOffsetFromCenter();
	void InitDefaultCommand();
	float GetTiltEnc();
	float GetRotateEnc();
	void Update(bool visionActive);
	void SetTarget(int newTarget);
	void SetTurretRotate(float speed);
	bool GetTurretCentered();
	bool GetTiltDown();
};

#endif
