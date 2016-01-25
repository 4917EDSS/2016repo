#ifndef DrivetrainSub_H
#define DrivetrainSub_H

#include "Commands/Subsystem.h"
#include "DrivetrainSub.h"
#include "WPILib.h"

class DrivetrainSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon *leftMotor;
	Talon *rightMotor;
public:
	DrivetrainSub();
	void InitDefaultCommand();
	void Drive(float leftSpeed, float rightSpeed);
};

#endif
