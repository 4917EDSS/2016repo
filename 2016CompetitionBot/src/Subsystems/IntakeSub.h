#ifndef IntakeSub_H
#define IntakeSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* intakeMotor;
	Talon* adjustMotor;
	Encoder* heightEncoder;
public:
	IntakeSub(int intakeMotorC, int adjustMotorC, int heightEncoder1C, int heightEncoder2C);
	void InitDefaultCommand();
	int GetHeight();
	int GetRawHeight();
	void SetVerticalSpeed(float speed);
	void SetIntakeSpeed(float speed);
};

#endif
