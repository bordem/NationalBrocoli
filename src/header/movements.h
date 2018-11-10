#ifndef DEF_MOUVEMENTS
#define DEF_MOUVEMENTS

#include "types.h"
#include "motor.h"

class Movements{
	private:
		Motor* motorLeft;
		Motor* motorRight;
		const float DISTANCE_CM_PAR_SECONDE = 29; //TODO On devrait renomer cette variable je trouve
	public:
		Movements(Motor* L, Motor* R);
		void backward(float distance);
		void forward(float distance);
		void stop();
		void doPath();
		void goAt(uchar speedMotorLeft, uchar speedMotorRight);
		void turn90(enum Pos direction, uchar speed=200);
		float getSpeed();
};

#endif /* end of include guard:  */
