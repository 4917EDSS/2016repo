#ifndef AutoParameterizedDriveCmd_H
#define AutoParameterizedDriveCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoParameterizedDriveCmd: public CommandBase
{
private:
	int remainingTicks;
public:
	AutoParameterizedDriveCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
