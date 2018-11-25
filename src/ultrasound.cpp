#include "ultrasound.h"

Ultrasound::Ultrasound(uchar port,int max_iter):sensor(port),iterations(max_iter){

}
bool Ultrasound::obstacleAt(float n){
	if(this->readDistance(3)<n){
		return true;
	}
	return false;
}
float Ultrasound::readDistance(int n=1){
	float retour = 0;
	for(int i=0;i<n;i++){
		retour = retour + sensor.distanceCm();
	}
	return retour/n;
}
