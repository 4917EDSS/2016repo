#ifndef LowBarTransformCmd_H
#define LowBarTransformCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowBarTransformCmd: public CommandBase
{
public:
	LowBarTransformCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
