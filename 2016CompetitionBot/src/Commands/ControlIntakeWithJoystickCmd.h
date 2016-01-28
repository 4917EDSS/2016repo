#ifndef ControlIntakeWithJoystickCmd_H
#define ControlIntakeWithJoystickCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlIntakeWithJoystickCmd: public CommandBase
{
public:
	ControlIntakeWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
