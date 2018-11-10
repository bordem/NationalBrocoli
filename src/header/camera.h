#ifndef DEF_CAMERA
#define DEF_CAMERA

#include <Pixy.h>
#include <SPI.h>

class Camera{
    private:
		Pixy pixy;
		int TAILLE_X;
		int X_CENTER;
		int Y_CENTER;
		int taillePartieBloc;

	public:
		Camera();
		int getTAILLE_X();
		Pixy& getPixy();
};
#endif
