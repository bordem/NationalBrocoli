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
	uchar speed=200;//Vitesse a passer aux moteur

	Serial.println("Forward");
	
	float distance_near = 10;
	float distance_far = 13;
	float distance_max = 19;
		
	unsigned long startTime = millis();
	while ( (millis() - startTime) < time*1000  ){
/*		Serial.print("Distance: ");
		Serial.print(ultraRight.readDistance());
		Serial.print(", ");
		Serial.println(ultraLeft.readDistance() );*/
		float distanceLeft = ultraLeft.readDistance(1);
		float distanceRight = ultraRight.readDistance(1);
		Serial.print("Distance: (");
		Serial.print(distanceLeft);
		Serial.print(", ");
		Serial.print(distanceRight);
		Serial.println(")");
		float ajustement = 30;
		//Controle moteur gauche
		if ( distanceLeft < distance_near || distanceLeft > 350 ) {
			motorLeft->forward(speed+ajustement+10);
		}
		else if ( distanceLeft < distance_max && distanceLeft > distance_far ){
			motorLeft->forward(speed-ajustement-10);
		}
		else {
			motorLeft->forward(speed);
		}

		// Controle moteur droit
		if ( distanceRight < distance_near || distanceRight > 350 ) {
			motorRight->forward(speed+ajustement);
		}
		else if ( distanceRight < distance_max && distanceRight > distance_far ){
			motorRight->forward(speed-ajustement);
		}
		else {
			motorRight->forward(speed);
		}
		//	motorLeft->forward(speed);
		//delay(100);

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
