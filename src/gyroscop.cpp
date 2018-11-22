#include <gyroscop.h>

//sensors{MeGyro(ports[0]),MeGyro(ports[1])},


Gyroscop::Gyroscop(uint8_t port, int max_iter):
sensor(MeGyro(port)),
iterations(max_iter)
{
	this->begin();
}

void Gyroscop::update(){
	sensor.fast_update();
//	delay(10);
}

void Gyroscop::begin(){
	delay(500);
	sensor.begin();
	delay(500);
}

double Gyroscop::getAngle(){
	this->update();
	//Serial.println(sensor.getAngleZ());
	return (int)(sensor.getAngleZ()+0.5); // round to closest int
}
