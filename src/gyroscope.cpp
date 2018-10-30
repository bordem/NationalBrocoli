#include <gyroscope.h>

Gyroscope::Gyroscope(uint8_t ports[2], int max_iter=3):
sensors{MeGyro(ports[0]),MeGyro(ports[1])},
gyro_nb(2),
iterations(max_iter)
{
	this->reset();
}

void Gyroscope::reset(){
	for ( int i=0; i<gyro_nb; i++){
		sensors[i].begin();
	}
}

double* Gyroscope::angle(){

	double xs=0, ys=0, zs=0;
	for (int i=0; i<gyro_nb; i++){
		sensors[i].update();
		xs+=sensors[i].getAngleX();
		ys+=sensors[i].getAngleY();
		zs+=sensors[i].getAngleZ();
	}
	double* vals = new double[3]{xs/this->gyro_nb, ys/this->gyro_nb, zs/this->gyro_nb};
	//double vals[3] = {xs, ys, zs};
//	Serial.print("x=");
//	Serial.println(vals[0]);
	return vals;
}
