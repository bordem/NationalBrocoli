#include "header/mouvements.h"


Mouvements::Mouvements(Motor* L, Motor* R):motorLeft(L),motorRight(R)
{}
void Mouvements::forward(float distance){
	/*
		Rappel :
			v=d/t
			d=v*t
			t=d/v

			Diametre roue 6.3cm
			Rayon roue 3.15 cm
			25 MM DC ENCODER MOTOR
			Gear Ratio 1:46
			185 RPM +/-10%
			DC 9.0 V
	*/

	float temps = 1;// Seconde
	float vitesseMoteur = 230;//Vitesse a passer aux moteurs
	//ESSAI 1 Utilisation du nombre de rotation
	/*
		int RPM = 135;
		int RPS = RPM/60;
		int ratio = 46;
		float r = 0.0315;
	*/
	//ESSAI 2 Utilisation de l'horloge
	/*
	ω = 2πf/Nm
	m = 2πf/ωm
	Where
		ω = angular speed (rad/s)
		f = clock frequency (Hz)
		m = number of clock cycles
		N = pulses per rotation

	long N = motorLeft->getPulse();
	int f = 16000000;
	float omega = (RPM*2*PI)/60;
	float m = (2*PI*f)/(omega*N);
	temps = f/m;
*/

//ESSAI 3 Utilisation de l'acceleration
// V=V0+accel*temps


	//float vitesse=RPS*ratio*r*PI;//Vitesse en m/s Dans l'idee c'est mieux mais a la zob bien aussi

	while(true){
		Serial.print("Temps : ");
		Serial.println(temps);
	}
	motorLeft->forward(vitesseMoteur);
	motorRight->forward(vitesseMoteur);
	delay(temps*1000);
	motorLeft->stop();
	motorRight->stop();
}
void Mouvements::backward(float distance){
	/*
		Rappel :
			v=d/t
			d=v*t
			t=d/v
	*/
	float temps = 1;// Seconde
	float vitesseMoteur = 200;//Vitesse a passer aux moteurs
	float vitesse=vitesseMoteur;//Vitesse en m/s Dans l'idee c'est mieux mais a la zob c'est bien aussi

	motorLeft->backward(vitesse);
	motorRight->backward(vitesse);
	delay(temps*1000);
	motorLeft->stop();
	motorRight->stop();
}

void Mouvements::do_Path(){

}
void Mouvements::turn90(char speed,bool orientation){

}
