#ifndef SpinupCmd_H
#define SpinupCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SpinupCmd: public CommandBase
{
public:
	SpinupCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
