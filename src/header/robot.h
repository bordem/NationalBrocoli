#ifndef DEF_ROBOT
#define DEF_ROBOT

#include "types.h"
#include "gyroscope.h"
#include "movements.h"
#include "ultrasound.h"
#include "motor.h"
#include "camera.h"

class Robot{
	private:
		Gyroscope& gyro;
		Movements& move;
		Camera cam;
		Ultrason& sound;

	public:
		Robot(Gyroscope gyro, Movements move, Ultrason sound);
		~Robot();
		void turn90(enum Pos direction);
		void doPath();
		void followObject();
};

#endif
