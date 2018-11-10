#include "header/mouvements.h"


Movements::Movements(Motor* L, Motor* R):motorLeft(L),motorRight(R)
{}

void Muvements::forward(float distance){
	/*	Rappel :	v=d/t	d=v*t	t=d/v

			Diametre roue 6.3cm
			Rayon roue 3.15 cm
			25 MM DC ENCODER MOTOR
			Gear Ratio 1:46
			185 RPM +/-10%
			DC 9.0 V
	*/

	//float temps = 1 ;
	float temps = (distance*100)/this->getConst();// Seconde
	float vitesseMoteur = 200;//Vitesse a passer aux moteur

	motorLeft->forward(vitesseMoteur);
	motorRight->forward(vitesseMoteur);
	delay(temps*1000);
	motorLeft->stop();
	motorRight->stop();
}
void Movements::backward(float distance){
	/*
		Rappel :	v=d/t	d=v*t	t=d/v
	*/
	float temps = (distance*100)/this->getConst();// Seconde
	float vitesseMoteur = 200;//Vitesse a passer aux moteurs

	motorLeft->backward(vitesseMoteur);
	motorRight->backward(vitesseMoteur);
	delay(temps*1000);
	motorLeft->stop();
	motorRight->stop();
}
void Movements::stop(){
	motorLeft->stop();
	motorRight->stop();
}

void Movements::turn90(){
	float vitesseMoteur = 200;//Vitesse a passer aux moteurs
	motorLeft->forward(vitesseMoteur);
	motorRight->backward(vitesseMoteur);
}

float Movements::getConst(){
	return DISTANCE_CM_PAR_SECONDE;
}
void Movements::goAt(char speedMotorLeft, char speedMotorRight){
	motorLeft->forward(speedMotorLeft);
	motorRight->forward(speedMotorRight);
}
