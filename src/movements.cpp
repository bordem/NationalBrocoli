#include "movements.h"

Movements::Movements(Motor* L, Motor* R):
	motorLeft(L),
	motorRight(R)
{}

void nop(){};

void Movements::forward(float distance, Gyroscop& gyro, Ultrasound& ulra){
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

	
	float distance_near = 9;
	float distance_far = 11;
	float distance_max = 20;
		
	unsigned long startTime = millis();
	while ( (millis() - startTime) < time*1000  ){
		float distance = 400;//ultra.readDistance(1);
		float ajustement = 30;
		float angle = gyro.getAngle();

/**/
		Serial.print("Distance: ");
		Serial.print(distance);
		if ( distance < distance_max || distance > 399 ){ // Il y a un mur, on peut l'utiliser
			if ( distance < distance_near || distance > 399 ) { // En considérant que l'ultra est à gauche, sinon il faut inersé les variations de vitesse sur le moteur gauche et droit
				Serial.println("motorLeft->forward(speed+ajustement);");
				Serial.println("motorRight->forward(speed-ajustement);");
			}
			else if ( distance > distance_far ){
				Serial.println("motorLeft->forward(speed-ajustement);");
				Serial.println("motorRight->forward(speed+ajustement);");
			}
			else {
				Serial.println("motorRight->forward(speed);");
				Serial.println("motorLeft->forward(speed);");
			}
		}
		else { // On utliiser le gyro
			if ( angle < 0 && angle > -5 ){
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
		}
/*/
		if ( distance < distance_max || distance > 399 ){ // Il y a un mur, on peut l'utiliser
			if ( distance < distance_near || distance > 399 ) { // En considérant que l'ultra est à gauche, sinon il faut inersé les variations de vitesse sur le moteur gauche et droit
				motorLeft->forward(speed+ajustement);
				motorRight->forward(speed-ajustement);
			}
			else if ( distance > distance_far ){
				motorLeft->forward(speed-ajustement);
				motorRight->forward(speed+ajustement);
			}
			else {
				motorRight->forward(speed);
				motorLeft->forward(speed);
			}
		}
		else { // On utliiser le gyro
			if ( angle < 0 && angle > -5 ){
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
