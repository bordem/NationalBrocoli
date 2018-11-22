#ifndef DEF_ULTRASON
#define DEF_ULTRASON

#include "types.h"
#include <MeUltrasonicSensor.h>

class Ultrasound{
	private:
		MeUltrasonicSensor sensor;
		const int iterations;

	public:
		Ultrasound(int port, int max_iter);
		float readDistance(int n=1);
		bool obstacleAt(float n);
};
#endif
