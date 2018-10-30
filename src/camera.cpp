#include "header/camera.h"

Camera::Camera(){
	pixy.init();
	TAILLE_X = (PIXY_MAX_X-PIXY_MIN_X);
	X_CENTER = ((PIXY_MAX_X-PIXY_MIN_X)/2);
	Y_CENTER = ((PIXY_MAX_Y-PIXY_MIN_Y)/2);
	taillePartieBloc = (TAILLE_X/8);
}
int Camera::getTAILLE_X()
{
	return TAILLE_X;
}
Pixy Camera::getPixy()
{
	return pixy;
}
