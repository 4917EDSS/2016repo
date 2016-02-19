#ifndef BallToIntakeCmd_H
#define BallToIntakeCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class BallToIntakeCmd: public CommandBase
{
private:
public:
	BallToIntakeCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
