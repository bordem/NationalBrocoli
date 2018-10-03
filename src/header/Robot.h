#pragma once

class Robot{
	private:
		Gyroscop gyro_group;
		Mouvements move;
		//Camera cam
		Ultrason sound;
		
	public:
		Robot(Gyroscop gyro,Mouvements move,Ultrason sound);
};
