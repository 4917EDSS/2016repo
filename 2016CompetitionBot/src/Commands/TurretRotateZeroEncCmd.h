#ifndef TurretRotateZeroEncCmd_H
#define TurretRotateZeroEncCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurretRotateZeroEncCmd: public CommandBase
{
public:
	TurretRotateZeroEncCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
