#pragma once
#include "movements.h"
void Movements::doPath(){
	this->forward(40);
//(0, 0) -> (-3, 0)
	this->turn90(LEFT);
	this->forward(120);
//(-3, 0) -> (-3, 3)
	this->turn90(RIGHT);
	this->forward(120);
//(-3, 3) -> (-4, 3)
	this->turn90(LEFT);
	this->forward(40);
//(-4, 3) -> (-4, 4)
	this->turn90(RIGHT);
	this->forward(40);
//(-4, 4) -> (-2, 4)
	this->turn90(RIGHT);
	this->forward(80);
//(-2, 4) -> (-2, 3)
	this->turn90(RIGHT);
	this->forward(40);
//(-2, 3) -> (0, 3)
	this->turn90(LEFT);
	this->forward(80);
//(0, 3) -> (0, 4)
	this->turn90(LEFT);
	this->forward(40);
//(0, 4) -> (-1, 4)
	this->turn90(LEFT);
	this->forward(40);
//(-1, 4) -> (-1, 5)
	this->turn90(RIGHT);
	this->forward(40);
}
