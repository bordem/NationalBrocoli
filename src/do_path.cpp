#include "robot.h"
void Robot::doPath(){
	move.forward(0.4, gyro, ultra);
//(0, 0) -> (-3, 0)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(1.2, gyro, ultra);
//(-3, 0) -> (-3, 3)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(1.2, gyro, ultra);
//(-3, 3) -> (-4, 3)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
//(-4, 3) -> (-4, 4)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
//(-4, 4) -> (-2, 4)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.8, gyro, ultra);
//(-2, 4) -> (-2, 3)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
//(-2, 3) -> (-2, 2)
	gyro.begin();
	move.forward(0.4, gyro, ultra);
//(-2, 2) -> (-2, 3)
	this->turn90(LEFT);
	gyro.begin();
	findObject();
	move.tweak(gyro);
	this->turn90(LEFT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
//(-2, 3) -> (0, 3)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.8, gyro, ultra);
//(0, 3) -> (0, 4)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
//(0, 4) -> (-1, 4)
	this->turn90(LEFT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
//(-1, 4) -> (-1, 5)
	this->turn90(RIGHT);
	gyro.begin();
	move.forward(0.4, gyro, ultra);
}
