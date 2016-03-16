#ifndef ReverseFlywheelCmd_H
#define ReverseFlywheelCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ReverseFlywheelCmd: public CommandBase
{
public:
	ReverseFlywheelCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
