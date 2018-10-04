#include "header/robot.h"

Robot::Robot(Gyroscope gyro, Mouvements move, Ultrason sound):
	gyro(gyro),
	move(move),
	sound(sound)
{}

