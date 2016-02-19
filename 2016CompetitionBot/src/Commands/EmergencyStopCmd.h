#ifndef EmergencyStopCmd_H
#define EmergencyStopCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class EmergencyStopCmd: public CommandBase
{
public:
	EmergencyStopCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
