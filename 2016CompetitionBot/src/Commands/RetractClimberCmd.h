#ifndef RetractClimberCmd_H
#define RetractClimberCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class RetractClimberCmd: public CommandBase
{
public:
	RetractClimberCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
