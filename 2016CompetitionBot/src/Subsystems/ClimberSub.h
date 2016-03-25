#ifndef ClimberSub_H
#define ClimberSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* ExtensionMotor;
public:
	ClimberSub();
	void InitDefaultCommand();
	void SetExtenderSpeed(float speed);
};

#endif
