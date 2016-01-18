#ifndef FireCmd_H
#define FireCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class FireCmd: public CommandBase
{
public:
	FireCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
