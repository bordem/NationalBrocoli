#include <MeMegaPi.h>
#include <Arduino.h>
#include <Wire.h>
#include <mouvements.h>

int main(void ){
	init();
	Serial.begin(9600);

	Motor mot2(SLOT_2,droite);
	Motor mot1(SLOT_1,gauche);

	Mouvements move(&mot1, &mot2);
	move.forward(1);
	

	return 0;
}
