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
	int target;


	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterSub();
	void Spin(float spinSpeed);
	float GetTargetOffsetFromCenter();
	float GetGripValue(std::string gripValue);
	float GetTargetDistance();
	void InitDefaultCommand();
	float GetRotateEnc();
	float GetRawRotateEnc();
	void Update(bool visionActive);
	void SetTarget(int newTarget);
	void SetTurretRotate(float speed);
	void RotateTurretClockwise(float speed);
	void RotateTurretCounterClockwise(float speed);
	bool GetTurretCentered();
	CANTalon* spinnerMotor;
};

#endif
