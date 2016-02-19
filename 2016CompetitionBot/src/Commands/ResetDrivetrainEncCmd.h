#ifndef ResetDrivetrainEncCmd_H
#define ResetDrivetrainEncCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetDrivetrainEncCmd: public CommandBase
{
public:
	ResetDrivetrainEncCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
