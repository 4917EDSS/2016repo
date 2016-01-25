#ifndef HopperSub_H
#define HopperSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class HopperSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* hopperMotor;
	DigitalInput* ballInLimit;
public:
	HopperSub(int hopperMotorC, int ballInLimitC);
	void InitDefaultCommand();
	bool IsBallIn();
	void SetHopperMotor(float speed);
};

#endif
