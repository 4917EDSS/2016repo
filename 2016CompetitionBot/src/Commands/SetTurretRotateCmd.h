#ifndef SetTurretRotateCmd_H
#define SetTurretRotateCmd_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetTurretRotateCmd: public CommandBase
{
private:
	int rotate;
	bool spinUp;
public:
	SetTurretRotateCmd(int rotate);
	SetTurretRotateCmd(int rotate, bool spinup);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
