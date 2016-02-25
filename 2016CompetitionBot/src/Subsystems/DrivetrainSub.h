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
	Talon* rightMotor1;
	DoubleSolenoid* driveLiftShifter;
	Encoder* leftDistanceEncoder;
	Encoder* rightDistanceEncoder;

	int controlState;
	float accelThreshold;

public:
	DrivetrainSub();
	void Drive(float leftSpeed, float rightSpeed);
	void ToggleControls();
	int GetControls();
	float GetAccelThresh();
	void SetAccelThresh(float accelThresh);
	int GetRawLeftEnc();
	int GetLeftEnc();
	int GetRawRightEnc();
	int GetRightEnc();
	void ShiftDrive(bool isDrive);
	bool GetGear();
	void InitDefaultCommand();
	void ResetDrive();

};

#endif
