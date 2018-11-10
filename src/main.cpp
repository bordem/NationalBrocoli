#include <MeMegaPi.h>
#include <Arduino.h>
#include <Wire.h>
#include <movements.h>
#include <ultrasound.h>
#include <gyroscope.h>
#include <robot.h>
#include <camera.h>
#include <pince.h>




int main(void ){
	init();
	Serial.begin(9600);

//	Motor mot1(SLOT_1, LEFT);
//	Motor mot2(SLOT_2, RIGHT);
//	Ultrason ultra(PORT6,5);
//	Mouvements move(&mot1, &mot2);
	Gyroscope gyro({PORT7,PORT6});
//	Pince pince(SLOT_4);

//	pince.close();
//	pince.open();


//	Robot robot(gyro,move,ultra);
	//robot.followObject();
	while(true){
		Serial.println(gyro.getAngle()[0]);
	}
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
