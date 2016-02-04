#ifndef AimBotCmd_H
#define AimBotCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AimBotCmd: public CommandBase
{
public:
	AimBotCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
