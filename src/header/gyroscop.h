#ifndef DEF_GYRO
#define DEF_GYRO

#include "types.h"
#include <MeGyro.h>

enum Axe{
	X=0,
	Y,
	Z
};

class Gyroscop{
	private:
		MeGyro sensor;
		const int iterations;

	public:
		Gyroscop(uint8_t port, int max_iter=3);
		void begin();
		double getAngle();
		void update();
};

#endif
