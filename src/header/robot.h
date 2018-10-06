#ifndef DEF_ROBOT
#define DEF_ROBOT

#include "gyroscope.h"
#include "mouvement.h"
#include "ultrasound.h"

class Robot{
	private:
		Gyroscop gyro_group;
		Mouvements move;
		//Camera cam
		Ultrason sound;

	public:
		Robot(Gyroscop gyro,Mouvements move,Ultrason sound);
};

#endif
