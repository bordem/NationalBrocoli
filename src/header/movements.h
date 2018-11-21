#ifndef DEF_MOUVEMENTS
#define DEF_MOUVEMENTS

#include "types.h"
#include "motor.h"
#include "ultrasound.h"
#include "gyroscope.h"

class Movements{
	private:
		Motor* motorLeft;
		Motor* motorRight;
		const float DISTANCE_CM_PAR_SECONDE = 46; //TODO On devrait renomer cette variable je trouve
	public:
		Movements(Motor* L, Motor* R);
		void backward(float distance);
		void forward(float distance, Ultrason&, Ultrason&);
		void stop();
		void goAt(int speedMotorLeft, int speedMotorRight);
		void turn(enum Pos direction);
		void tweak(Gyroscope& gyro); 
		float getSpeed();
};

#endif /* end of include guard:  */
