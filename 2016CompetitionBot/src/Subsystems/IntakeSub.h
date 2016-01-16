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
	DigitalInput* ballHitLimit;
public:
	IntakeSub(int intakeMotorC, int ballHitLimitC);
	void InitDefaultCommand();
	bool IsBallLoaded();
	void SetIntakeSpeed(float speed);
};

#endif
