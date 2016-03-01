#ifndef BallToShooterCmd_H
#define BallToShooterCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class BallToShooterCmd: public CommandBase
{
private:
	double timeSinceBallInShooter;
public:
	BallToShooterCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
