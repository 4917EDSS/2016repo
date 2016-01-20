#ifndef AutoGenericDuoGrp_H
#define AutoGenericDuoGrp_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoGenericDuoGrp: public CommandGroup
{
public:
	AutoGenericDuoGrp(Command* defenceCmd, Command* shootCmd);
};

#endif
