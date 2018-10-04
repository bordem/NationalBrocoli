#pragma once

#include "header/gyroscope.h"
#include "header/mouvement.h"
#include "header/untrasound.h"


class Robot{
	private:
		Gyroscop gyro_group;
		Mouvements move;
		//Camera cam
		Ultrason sound;
		
	public:
		Robot(Gyroscop gyro,Mouvements move,Ultrason sound);
};
