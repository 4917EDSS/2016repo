#ifndef DriveStraightCmd_H
#define DriveStraightCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStraightCmd: public CommandBase
{
private:
public:
	DriveStraightCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
