#include <gyroscope.h>

//sensors{MeGyro(ports[0]),MeGyro(ports[1])},

Gyroscope::Gyroscope(uint8_t port, int max_iter):
sensor(MeGyro(port)),
iterations(max_iter)
{
	this->begin();
}

void Gyroscope::update(){
	sensor.update();
	delay(10);
}

void Gyroscope::begin(){
	delay(1000);
	sensor.begin();
	delay(1000);
}

double Gyroscope::getAngle(){
	sensor.update();
	return sensor.getAngleZ();
}
