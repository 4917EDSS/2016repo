#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* leftMotor1;
	Talon* leftMotor2;
	Talon* rightMotor1;
	Talon* rightMotor2;
	Encoder* leftDistanceEncoder;
	Encoder* rightDistanceEncoder;

	int controlState;
	float accelThreshold;

public:
	DrivetrainSub(int leftMotor1C, int leftMotor2C, int rightMotor1C, int rightMotor2C, int leftEncoder1C, int leftEncoder2C, int rightEncoder1C, int rightEncoder2C);
	void Drive(float leftSpeed, float rightSpeed);
	void ToggleControls();
	int GetControls();
	float GetAccelThresh();
	void SetAccelThresh(float accelThresh);
	int GetRawLeftEnc();
	int GetLeftEnc();
	int GetRawRightEnc();
	int GetRightEnc();
	void InitDefaultCommand();
	void ResetDrive();

};

#endif
