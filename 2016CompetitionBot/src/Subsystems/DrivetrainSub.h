#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "Components/MotorBalancer.h"
#include "WPILib.h"
#include "AHRS.h"

#define FROM_DASHBOARD_SPEED -1000000.0
#define FROM DASHBOARD_DISTANCE -1000000

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
	PIDController* driveBalanceController;
	PIDController* driveTurnController;
	AHRS* ahrs;
	MotorBalancer* motorBalancer;
	MotorBalancer* motorTurner;

	int controlState;
	float accelThreshold;

public:
	DrivetrainSub();
	void Drive(float leftSpeed, float rightSpeed);
	void PIDDrive(float speed);
	void EnableBalancerPID(float setPoint);
	void DisableBalancerPID();
	void PIDTurn();
	void EnableTurnPID(float setPoint);
	void DisableTurnPID();
	bool IsTurnFinished();
	void ToggleControls();
	int GetControls();
	float GetAccelThresh();
	float GetYaw();
	void SetAccelThresh(float accelThresh);
	int GetRawLeftEnc();
	int GetLeftEnc();
	int GetRawRightEnc();
	int GetRightEnc();
	void ShiftDrive(bool isDrive);
	bool GetGear();
	AHRS* GetAHRS();
	void InitDefaultCommand();
	void ResetDrive();

};

#endif
