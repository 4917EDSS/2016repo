#ifndef SetTurretRotateCmd_H
#define SetTurretRotateCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetTurretRotateCmd: public CommandBase
{
private:
	int rotate;
public:
	SetTurretRotateCmd(int rotate);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
