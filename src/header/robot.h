#ifndef DEF_ROBOT
#define DEF_ROBOT

#include "types.h"
#include "gyroscop.h"
#include "movements.h"
#include "ultrasound.h"
#include "motor.h"
#include "camera.h"
#include "pince.h"
#include "arm.h"

class Robot{
	private:
		Gyroscop& gyro;
		Movements& move;
		Camera cam;
		Ultrasound& ultra;
		Pince pince;
		Arm bras;

	public:
		Robot(Gyroscop& gyro, Movements& move, Ultrasound& soud);
		~Robot();
		void turn90(enum Pos direction);
		void doPath();
		void findObject();
};

#endif
