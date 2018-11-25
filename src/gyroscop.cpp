#include <gyroscop.h>


Gyroscop::Gyroscop(uchar port, int max_iter):
	sensor(port),
	iterations(max_iter)
{}

void Gyroscop::begin(){
	sensor.begin();
}

void Gyroscop::update(){
	sensor.update();
}

double Gyroscop::getAngle(){
	return (int)(sensor.getAngleX() + 0.5);
}
