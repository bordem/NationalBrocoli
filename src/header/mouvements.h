#ifndef DEF_MOUVEMENTS
#define DEF_MOUVEMENTS

#include "types.h"
#include "motor.h"

class Mouvements{
	private:
		Motor& motorLeft;
		Motor& motorRight;
	public:
		Mouvements(Motor L, Motor R);
		void backward(float distance);
		void forward(float distance);
		void do_Path();
		void turn90(char speed,bool orientation);
};

#endif /* end of include guard:  */
