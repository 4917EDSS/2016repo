#ifndef SetIntakeHeightCmd_H
#define SetIntakeHeightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetIntakeHeightCmd: public CommandBase
{
private:
	int height;
public:
	SetIntakeHeightCmd(int destination);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
