#ifndef SetHoodHeightCmd_H
#define SetHoodHeightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetHoodHeightCmd: public CommandBase
{
private:
	int height;
public:
	SetHoodHeightCmd(int height);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
