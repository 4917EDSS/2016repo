/*
 * Encoder4917.h
 *
 *  Created on: Feb 21, 2015
 *      Author: TEAM 4917
 */

#ifndef SRC_COMMANDS_ENCODER4917_H_
#define SRC_COMMANDS_ENCODER4917_H_

#include "WPILib.h"

class Encoder4917 : public PIDSource{
private:
	Encoder* m_encoder;
public:
	Encoder4917(uint32_t channel1 , uint32_t channel2);
	virtual ~Encoder4917();
	double PIDGet();
	Encoder* GetEncoder();
	void SetDistancePerPulse(float distancePerPulse);
	int GetRaw();
	float GetDistance();
	float GetRate();

};

#endif /* SRC_COMMANDS_ENCODER4917_H_ */
