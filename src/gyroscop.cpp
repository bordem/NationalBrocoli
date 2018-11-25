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
	update();
	return (int)(sensor.getAngleZ() + 0.5);
}
