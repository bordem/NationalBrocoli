#include <ultrasound.h>

Ultrasound::Ultrasound(int p, int max_iter):iterations(max_iter),sensor(p){
}
float Ultrasound::readDistance(int n=1){
	n = (n > iterations)? n : iterations;
	int const tailleTableau=n;
	float tableauDistance[tailleTableau];
	for(int i=0;i<tailleTableau;i++)
		tableauDistance[i]=sensor.distanceCm();


	if(n >1){
		for(int i=1; i<n-1;i++){
	        int min = i;
	        for(int j=i+1;j<n;j++){
				if (tableauDistance[j] < tableauDistance[min]){
					min = j;
				}
			}
			if(min != i){
				float swt=tableauDistance[i];
				tableauDistance[i]=tableauDistance[min];
				tableauDistance[min]=swt;
			}
		}
		return tableauDistance[tailleTableau/2];
	}
	else{
		return tableauDistance[0];
	}
}
bool Ultrasound::obstacleAt(float n){
	if(this->readDistance(3)<n)
		return true;
	return false;
}
