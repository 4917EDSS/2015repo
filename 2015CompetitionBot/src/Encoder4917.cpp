/*
 * Encoder4917.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: TEAM 4917
 */

#include <Encoder4917.h>

Encoder4917::Encoder4917(uint32_t channel1 , uint32_t channel2) : PIDSource(){
	mEncoder =  new Encoder(channel1, channel2);

}

Encoder4917::~Encoder4917() {
	// TODO Auto-generated destructor stub
}
double Encoder4917::PIDGet(){
	return mEncoder->GetRate();
}
Encoder* Encoder4917::GetEncoder(){
	return mEncoder;
}
void Encoder4917::SetDistancePerPulse(float distancePerPulse){
	mEncoder->SetDistancePerPulse(distancePerPulse);
}
int Encoder4917::GetRaw(){
	return mEncoder->GetRaw();
}
float Encoder4917::GetDistance(){
	return mEncoder->GetDistance();
}
float Encoder4917::GetRate(){
	return mEncoder->GetRate();
}
