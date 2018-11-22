#include "robot.h"
void Robot::doPath(){
	move.forward(30, gyro, ultra);
//(0, 0) -> (-3, 0)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(1.2, gyro, ultra);
	move.tweak(gyro);
//(-3, 0) -> (-3, 3)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(1.2, gyro, ultra);
	move.tweak(gyro);
//(-3, 3) -> (-4, 3)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
	move.tweak(gyro);
//(-4, 3) -> (-4, 4)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
	move.tweak(gyro);
//(-4, 4) -> (-2, 4)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.8, gyro, ultra);
	move.tweak(gyro);
//(-2, 4) -> (-2, 3)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
	move.tweak(gyro);
//(-2, 3) -> (0, 3)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(0.8, gyro, ultra);
	move.tweak(gyro);
//(0, 3) -> (0, 4)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
	move.tweak(gyro);
//(0, 4) -> (-1, 4)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
	move.tweak(gyro);
//(-1, 4) -> (-1, 5)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
	move.tweak(gyro);
}
