#include <gyroscope.h>

//sensors{MeGyro(ports[0]),MeGyro(ports[1])},

Gyroscope::Gyroscope(uint8_t port, int max_iter):
sensor(MeGyro(port)),
iterations(max_iter)
{
	this->begin();
}

void Gyroscope::update(){
	sensor.fast_update();
//	delay(10);
}

void Gyroscope::begin(){
	delay(500);
	sensor.begin();
	delay(500);
}

double Gyroscope::getAngle(){
	this->update();
	Serial.println(sensor.getAngleZ());
	return sensor.getAngleZ();
}
