#ifndef ControlHoodWithJoystickCmd_H
#define ControlHoodWithJoystickCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlHoodWithJoystickCmd: public CommandBase
{
public:
	ControlHoodWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
