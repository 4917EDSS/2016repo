#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<Talon> leftMotor1;
	std::unique_ptr<Talon> leftMotor2;
	std::unique_ptr<Talon> rightMotor1;
	std::unique_ptr<Talon> rightMotor2;

	int controlState;
	float accelThreshold;

public:
	DrivetrainSub(int leftMotor1C, int leftMotor2C, int rightMotor1C, int rightMotor2C);
	void Drive(float leftSpeed, float rightSpeed);
	void ToggleControls();
	int GetControls();
	float GetAccelThresh();
	void SetAccelThresh(float accelThresh);
	void InitDefaultCommand();
};

#endif
