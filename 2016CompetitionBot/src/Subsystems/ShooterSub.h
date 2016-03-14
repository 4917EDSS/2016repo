#ifndef ShooterSub_H
#define ShooterSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Components/Encoder4917.h"

class ShooterSub: public Subsystem
{
private:

	Talon* rotateTurretMotor;
	Encoder4917* shooterEncoder;
	Encoder* rotateEncoder;
	DigitalInput* turretCentered;
	int rotateSetpoint;
	bool sideOfShooter;
	float maxRightEnc;
	float maxRightOffset;
	float minLeftEnc;
	float minLeftOffset;
	float centerEnc;
	int x;


	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterSub();
	void Spin(float spinSpeed);
	float GetTargetOffsetFromCenter();
	void InitDefaultCommand();
	float GetRawRotateEnc();
	void ResetRotate();
	void Update(bool visionActive);
	void SetTarget(int newTarget);
	bool IsOnTarget();
	void SetTurretRotate(float speed);
	void RotateTurretClockwise(float speed);
	void RotateTurretCounterClockwise(float speed);
	void RotateWithEncoder();
	void ResetAutoShot();
	bool GetTurretCentered();
	CANTalon* spinnerMotor;
};

#endif
