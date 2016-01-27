#ifndef ControlTurretWithJoystickCmd_H
#define ControlTurretWithJoystickCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlTurretWithJoystickCmd: public CommandBase
{
public:
	ControlTurretWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
