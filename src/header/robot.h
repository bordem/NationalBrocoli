#ifndef DEF_ROBOT
#define DEF_ROBOT

#include "types.h"
#include "gyroscope.h"
#include "mouvements.h"
#include "ultrasound.h"
#include "motor.h"
#include "camera.h"

class Robot{
	private:
		Gyroscope& gyro_group;
		Mouvements& move;
		Camera cam;
		Ultrason& sound;

	public:
		Robot(Gyroscope gyro, Mouvements move, Ultrason sound);
		~Robot();
		void do_path();
		void followObject();
		void turn90();
};

#endif
