#ifndef DriveTurnCmd_H
#define DriveTurnCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTurnCmd: public CommandBase
{
private:
	int turnEncoderValues;
	bool isClockwiseTurn;
	float driveSpeed;
	int previousLeftEncoder;
	int previousRightEncoder;

public:
	DriveTurnCmd(int turnDegrees, bool isClockwiseTurnParam, float driveSpeedParam);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
