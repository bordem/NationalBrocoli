#ifndef DEF_GYRO
#define DEF_GYRO

#include "types.h"
#include <MeGyro.h>

class Gyroscope{
	private:
		uchar ports[];
		MeGyro sensor[];
		const int gyro_nb;
		const int iterations;

	public:
		Gyroscope(uchar port[2], int max_iter);
		void reset();
		double angle();
};

#endif
