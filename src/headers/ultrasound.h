#ifndef ULTRASOUND
#define  ULTRASOUND

#include <MeUltrasonicSensor.h>
#include "types.h"

	class Ultrasound{
		private:
			MeUltrasonicSensor sensor;
			const int iterations;
		public:
			Ultrasound(uchar port,int max_iter);
			bool obstacleAt(float n);
			float readDistance(int n=1);
	};
#endif
