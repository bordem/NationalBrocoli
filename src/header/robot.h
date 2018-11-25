#ifndef ROBOT
#define ROBOT

#include "ultrasound.h"
#include "arm.h"
#include "gyroscop.h"
#include "movements.h"
#include "pince.h"
#include "camera.h"

class Robot{
	private:
		Gyroscop gyro;
		Movements move;
		Pince pince;
		Arm bras;
		Camera cam;
		Ultrasound ultra;

	public:
		Robot(Gyroscop gyro, Movements move,Ultrasound sound);
		void doPath();
		void findObject();
};
#endif
