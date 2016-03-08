#include "PidAhrs.h"
/*
 * PidAhrs.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: 4917
 */

PidAhrs::PidAhrs(AHRS* ahrs) : m_ahrs(ahrs) {}

double PidAhrs::PIDGet() {
	return m_ahrs->GetYaw();// DO NOT CHANGE TO GET ANGLE - MESSES UP STRAIGHT DRIVING
}
