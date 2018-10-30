#ifndef DEF_MOUVEMENTS
#define DEF_MOUVEMENTS

#include "types.h"
#include "motor.h"

class Mouvements{
	private:
		Motor* motorLeft;
		Motor* motorRight;
		const float DISTANCE_CM_PAR_SECONDE = 29;
	public:
		Mouvements(Motor* L, Motor* R);
		void backward(float distance);
		void forward(float distance);
		void stop();
		void goAt(char speedMotorGauche, char speedMotorDroit);
		void turn90();
		float getConst();
};

#endif /* end of include guard:  */
