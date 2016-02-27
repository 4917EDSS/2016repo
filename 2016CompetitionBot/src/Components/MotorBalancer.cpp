/*
 * MotorBalancer.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: 4917
 */

#include <Components/MotorBalancer.h>

MotorBalancer::MotorBalancer() {
	difference = 0;
}

void MotorBalancer::PIDWrite(float output) {
	difference = output;
}

float MotorBalancer::GetDifference() {
	return difference;
}

void MotorBalancer::Reset() {
	difference = 0;
}
