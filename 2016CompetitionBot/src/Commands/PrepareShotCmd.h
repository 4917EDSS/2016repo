#ifndef PrepareShotCmd_H
#define PrepareShotCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class PrepareShotCmd: public CommandBase
{
public:
	PrepareShotCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
