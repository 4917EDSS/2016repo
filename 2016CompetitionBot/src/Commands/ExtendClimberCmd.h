#ifndef ExtendClimberCmd_H
#define ExtendClimberCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExtendClimberCmd: public CommandBase
{
public:
	ExtendClimberCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
