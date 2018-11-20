#include "movements.h"

Movements::Movements(Motor* L, Motor* R):
	motorLeft(L),
	motorRight(R)
{}

void nop(){};

void Movements::forward(float distance, Ultrason& ultraLeft, Ultrason& ultraRight){
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

	Serial.println("Forward");
	
	float distance_wall = 10;
		
	unsigned long startTime = millis();
	while ( (millis() - startTime) < time*1000  ){
		if ( ultraLeft.readDistance() < distance_wall ) {
			motorRight->forward(speed-30);
			motorLeft->forward(speed+30);
		}
		else if ( ultraRight.readDistance() < distance_wall){
			motorLeft->forward(speed-30);
			motorRight->forward(speed+30);
		}
		else {
			motorLeft->forward(speed);
			motorRight->forward(speed);
		}
	}
	this->stop();
}

void Movements::tweak(Gyroscope& gyro){
	delay(500);
	float angle = gyro.getAngle();
	if ( angle < 0 ){
		this->turn(LEFT);
		while ( gyro.getAngle() < 0 );
	}
	else {
		this->turn(RIGHT);
		while ( gyro.getAngle() > 0 );
	}
	this->stop();
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
	this->stop();
}
void Movements::stop(){
	Serial.println("Stop");
	motorLeft->stop();
	motorRight->stop();
}

void Movements::turn(enum Pos direction){
	if ( direction == RIGHT ){
		motorLeft->forward(60);
		motorRight->backward(60);
	}
	else {
		motorLeft->backward(60);
		motorRight->forward(60);
	}
}

float Movements::getSpeed(){
	return DISTANCE_CM_PAR_SECONDE;
}

void Movements::goAt(int speedMotorLeft, int speedMotorRight){
	motorLeft->forward(speedMotorLeft);
	motorRight->forward(speedMotorRight);
}
