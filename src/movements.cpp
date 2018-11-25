#include "movements.h"

Movements::Movements(Motor* L, Motor* R):
	motorLeft(L),
	motorRight(R)
{}

void nop(){};

void Movements::forward(float distance, Gyroscop& gyro, Ultrasound& ultra){
	/*	Rappel :	v=d/t	d=v*t	t=d/v

			Diametre roue 6.3cm
			Rayon roue 3.15 cm
			25 MM DC ENCODER MOTOR
			Gear Ratio 1:46
			185 RPM +/-10%
			DC 9.0 V
	*/
	float time = (distance*100)/this->getSpeed();// Seconde
	uchar speed=200;//Vitesse a passer aux moteur

	float distance_near = 9;
	float distance_far = 11;
	float distance_max = 20;

	unsigned long startTime = millis();
	while ( (millis() - startTime) < time*1000  ){
		bool mur = ultra.obstacleAt(7);
		float ajustement = 30;
		float angle = gyro.getAngle();
/*/
		Serial.print("Angle:");
		Serial.println(angle);
		if ( mur ){
			Serial.println("Obstruction");
			continue;
		}
		if ( angle < 0 && angle < -5 ){
			Serial.println("motorRight->forward(speed+ajustemnt);");
			Serial.println("motorLeft->forward(speed-ajustemnt);");
		}
		else if ( angle > 0 && angle < 5 ){
			Serial.println("motorRight->forward(speed-ajustement);");
			Serial.println("motorLeft->forward(speed+ajustement);");
		}
		else {
			Serial.println("motorRight->forward(speed);");
			Serial.println("motorLeft->forward(speed);");
		}
		delay(1000);
/*/
		if ( mur ){
			break;
		}
		if ( angle < 0 && angle < -5 ){
			motorRight->forward(speed+ajustement);
			motorLeft->forward(speed-ajustement);
		}
		else if ( angle > 0 && angle < 5 ){
			motorRight->forward(speed-ajustement);
			motorLeft->forward(speed+ajustement);
		}
		else {
			motorRight->forward(speed);
			motorLeft->forward(speed);
		}
/**/
	}
	this->stop();
}

void Movements::tweak(Gyroscop& gyro){
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
		motorLeft->forward(100);
		motorRight->backward(100);
	}
	else {
		motorLeft->backward(100);
		motorRight->forward(100);
	}
}

float Movements::getSpeed(){
	return DISTANCE_CM_PAR_SECONDE;
}

void Movements::goAt(uchar speedMotorLeft, uchar speedMotorRight){
	motorLeft->forward(speedMotorLeft);
	motorRight->forward(speedMotorRight);
}
