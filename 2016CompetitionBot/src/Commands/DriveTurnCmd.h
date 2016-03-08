#ifndef DriveTurnCmd_H
#define DriveTurnCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTurnCmd: public CommandBase
{
private:
	float turnDegrees;
	float lastCheckpoint;
	double lastCheckpointTime;

public:
	DriveTurnCmd(float turnDegrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
