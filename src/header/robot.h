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
		Robot(uchar port_gyro,uchar port_sound,uchar port_M1,uchar port_M2);
		void doPath();
		void findObject();
		void turn90(Pos direction);
};
#endif
