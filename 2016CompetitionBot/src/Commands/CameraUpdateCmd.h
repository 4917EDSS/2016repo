#ifndef CameraUpdateCmd_H
#define CameraUpdateCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class CameraUpdateCmd: public CommandBase
{
private:
	double prevTime;
public:
	CameraUpdateCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
