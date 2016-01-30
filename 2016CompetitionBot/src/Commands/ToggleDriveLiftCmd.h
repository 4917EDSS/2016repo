#ifndef ToggleDriveLiftCmd_H
#define ToggleDriveLiftCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleDriveLiftCmd: public CommandBase
{
public:
	ToggleDriveLiftCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
