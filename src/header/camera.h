#ifndef CAMERA
#define CAMERA

#include <Pixy.h>

	class Camera{
		private:
			Pixy pixy;
			int TAILLE_X;
			int X_CENTER;
			int Y_CENTER;
			int taillePartieBloc;
		public:
			Camera();
			Pixy getPixy();
			int getTaille_X();
	};
#endif
