#ifndef SetHoodHeightCmd_H
#define SetHoodHeightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetHoodHeightCmd: public CommandBase
{
private:
	int height;
	bool exitWhenAtTarget;
public:
	SetHoodHeightCmd(int height);
	SetHoodHeightCmd(int height, bool exitAtTarget);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
