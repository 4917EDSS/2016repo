#ifndef ShooterSub_H
#define ShooterSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Components/Encoder4917.h"

class ShooterSub: public Subsystem
{
private:
	Talon* spinnerMotor;
	Encoder4917* shooterEncoder;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterSub(int shooterMotorC, int shooterEncoder1C, int shooterEncoder2C);
	void Spin(float spinSpeed);
	void InitDefaultCommand();
};

#endif
