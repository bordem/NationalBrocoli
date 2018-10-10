#include <gyroscope.h>

Gyroscope::Gyroscope(uint8_t ports[2], int max_iter):
sensors{MeGyro(ports[0]),MeGyro(ports[1])},
gyro_nb{2},
iterations{max_iter}
{}

void Gyroscope::rese(){
	
}

double Gyroscope::angle(){
	return 0;
}
