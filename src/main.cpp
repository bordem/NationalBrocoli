#include <MeMegaPi.h>
#include <Arduino.h>
#include <motor.h>

int main(void ){

	Serial.begin(9600);
	init();

	//Motor mot1(SLOT_1,droite);
	//Motor mot2(SLOT_2,gauche);


	return 0;
}
