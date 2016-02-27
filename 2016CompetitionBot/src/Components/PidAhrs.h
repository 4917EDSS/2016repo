#ifndef SRC_COMMANDS_PID_AHRS_H_
#define SRC_COMMANDS_PID_AHRS_H_

#include "WPILib.h"
#include "AHRS.h"

class PidAhrs : public PIDSource{
private:
	AHRS* m_ahrs;
public:
	PidAhrs(AHRS* ahrs);
	double PIDGet();

};

#endif
