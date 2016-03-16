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
	DigitalInput* intakeUpLimit;
	int targetHeight;
public:
	IntakeSub();
	void InitDefaultCommand();
	void SetHeight(int height);
	int GetHeight();
	bool GetIntakeUp();
	int GetRawHeight();
	void Update();
	bool IsOnTarget();
	void SetVerticalSpeed(float speed);
	void SetIntakeSpeed(float speed);
};

#endif
