#ifndef ControlHopperWithJoystickCmd_H
#define ControlHopperWithJoystickCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlHopperWithJoystickCmd: public CommandBase
{
public:
	ControlHopperWithJoystickCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
