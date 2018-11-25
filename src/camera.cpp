#include "camera.h"

Camera::Camera(){
	pixy.init();
}
Pixy Camera::getPixy(){
	return this->pixy;
}
int Camera::getTaille_X(){
	return PIXY_MAX_X;
}
