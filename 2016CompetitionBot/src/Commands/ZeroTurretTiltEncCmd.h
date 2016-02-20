#ifndef ZeroTurretTiltEncCmd_H
#define ZeroTurretTiltEncCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ZeroTurretTiltEncCmd: public CommandBase
{
public:
	ZeroTurretTiltEncCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
