#ifndef DEF_ROBOT
#define DEF_ROBOT

#include "types.h"
#include "gyroscop.h"
#include "movements.h"
#include "ultrasound.h"
#include "motor.h"
#include "camera.h"

class Robot{
	private:
		Gyroscop& gyro;
		Movements& move;
		Camera cam;
		Ultrasound& ultra;

	public:
		Robot(Gyroscop& gyro, Movements& move, Ultrasound& soud);
		~Robot();
		void turn90(enum Pos direction);
		void doPath();
		void followObject();
};

#endif
