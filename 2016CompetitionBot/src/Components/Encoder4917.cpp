/*
 * Encoder4917.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: TEAM 4917
 */

#include "Encoder4917.h"


// Encoder4917 is a class that changes a distance quadrature encoder to a speed encoder.
// It overrides the PIDGet method such that the rate is returned rather than the distance.
// The base class "Encode" actually implements PIDGet as kDistance or kRate but there doesn't
// seem to be any way to tell it to use kRate.
Encoder4917::Encoder4917(uint32_t channel1 , uint32_t channel2) : PIDSource(){
	m_encoder = new Encoder(channel1, channel2);

}

Encoder4917::~Encoder4917() {
	if( m_encoder )
	{
		delete m_encoder;
	}
}
double Encoder4917::PIDGet(){
	// Return rate instead of distance
	return m_encoder->GetRate();
}
Encoder* Encoder4917::GetEncoder(){
	return m_encoder;
}
void Encoder4917::SetDistancePerPulse(float distancePerPulse){
	m_encoder->SetDistancePerPulse(distancePerPulse);
}
int Encoder4917::GetRaw(){
	return m_encoder->GetRaw();
}
float Encoder4917::GetDistance(){
	return m_encoder->GetDistance();
}
float Encoder4917::GetRate(){
	return m_encoder->GetRate();
}



