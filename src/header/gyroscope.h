#ifndef DEF_GYRO
#define DEF_GYRO

#include "types.h"
#include <MeGyro.h>


class Gyroscope{
	private:
		MeGyro sensors[2];
		const int gyro_nb;
		const int iterations;

	public:
		enum Axe{
			X=0,
			Y,
			Z
		};
		Gyroscope(uint8_t ports[2], int max_iter);
		void reset();
		double* getAngle();
};

#endif
