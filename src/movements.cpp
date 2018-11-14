#include "movements.h"
#include "gyroscope.h"


Movements::Movements(Motor* L, Motor* R):
	motorLeft(L),
	motorRight(R)
{}

void Movements::forward(float distance){
	/*	Rappel :	v=d/t	d=v*t	t=d/v

			Diametre roue 6.3cm
			Rayon roue 3.15 cm
			25 MM DC ENCODER MOTOR
			Gear Ratio 1:46
			185 RPM +/-10%
			DC 9.0 V
	*/

	//float time = 1 ;
	float time = (distance*100)/this->getSpeed();// Seconde
	uchar speed = 200;//Vitesse a passer aux moteur

	motorLeft->forward(speed);
	motorRight->forward(speed);
	delay(time*1000);
	motorLeft->stop();
	motorRight->stop();
}
void Movements::backward(float distance){
	/*
		Rappel :	v=d/t	d=v*t	t=d/v
	*/
	float time = (distance*100)/this->getSpeed();// Seconde
	float speed = 200;//Vitesse a passer aux moteurs

	motorLeft->backward(speed);
	motorRight->backward(speed);
	delay(time*1000);
	motorLeft->stop();
	motorRight->stop();
}
void Movements::stop(){
	motorLeft->stop();
	motorRight->stop();
}

void Movements::turn(enum Pos direction){
	if ( direction == LEFT ){
		motorLeft->forward(150);
		motorRight->backward(150);
	}
	else {
		motorLeft->backward(150);
		motorRight->forward(150);
	}
}

float Movements::getSpeed(){
	return DISTANCE_CM_PAR_SECONDE;
}
void Movements::goAt(int speedMotorLeft, int speedMotorRight){
	motorLeft->forward(speedMotorLeft);
	motorRight->forward(speedMotorRight);
}
