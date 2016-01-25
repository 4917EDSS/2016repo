#ifndef IdleCmd_H
#define IdleCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class IdleCmd: public CommandBase
{
public:
	IdleCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
