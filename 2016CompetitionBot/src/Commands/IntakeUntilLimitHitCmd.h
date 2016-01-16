#ifndef IntakeUntilLimitHitCmd_H
#define IntakeUntilLimitHitCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeUntilLimitHitCmd: public CommandBase
{
public:
	IntakeUntilLimitHitCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
