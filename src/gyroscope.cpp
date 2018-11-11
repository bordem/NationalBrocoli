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

double Gyroscope::angle(){
	double x[this->iterations];
	for ( int j=0; j<this->iterations; j++){
		for ( int i=0; i<this->gyro_nb; i++){
			sensors[i].update();
			x[j]+=(sensors[i].getAngleX()/this->gyro_nb);
		}
//		Serial.println("Val dans la fonction");
//		Serial.println(xs);
	}

	int val, min, max;
	if ( x[0] > x[1] ){ // first choose min and max between 0 and 1
		max=1;
		min=0;
	}
	else {
		max=0;
		min=1;
	}
	if ( x[2] < min  ){ // then compare 2 to the min
		val=min;
		min=2;
	}
	else if ( x[2] > max  ) { // and the max
		val=max;
		max=2;
	}
	else {
		val=2;
	}
	Serial.print("Min: ");
	Serial.print(min);
	Serial.print("\tVal: ");
	Serial.print(val);
	Serial.print("\tMax: ");
	Serial.println(max);
	return x[val];
}
