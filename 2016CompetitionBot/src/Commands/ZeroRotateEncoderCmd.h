#ifndef ZeroRotateEncoderCmd_H
#define ZeroRotateEncoderCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class ZeroRotateEncoderCmd: public CommandBase
{
public:
	ZeroRotateEncoderCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
