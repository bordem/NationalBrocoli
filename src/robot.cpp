#include "robot.h"

Robot::Robot(Gyroscope* gyro, Mouvements* move, Ultrason* sound):
	gyro_group(gyro),
	move(move),
	sound(sound)
{}

