#include <MeMegaPi.h>
#include <Arduino.h>
#include <Wire.h>
#include <mouvements.h>
#include <ultrasound.h>
#include <gyroscope.h>
#include <robot.h>
#include <camera.h>
#include <pince.h>




int main(void ){
	init();
	Serial.begin(9600);

	Motor mot1(SLOT_1,gauche);
	Motor mot2(SLOT_2,droite);
	Ultrason ultra(PORT6,5);
	Mouvements move(&mot1, &mot2);
	Gyroscope gyro({PORT7,PORT6});
	Pince pince(SLOT_4);

	pince.close();
	pince.open();


	Robot robot(gyro,move,ultra);
	//robot.followObject();
	//while(true){
	//	gyro.getAngle();
	//}
	/*while(true){
		Serial.print("Voila : ");
		Serial.print(ultra.obstacleAt(100));
		Serial.print(" ");
		Serial.println(ultra.readDistance(500));
	}*/

	//move.forward(1);
	//robot.turn90();

	return 0;
}
