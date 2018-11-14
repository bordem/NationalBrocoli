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
	Serial.begin(115200);

	Motor mot1(SLOT_1, LEFT);
	Motor mot2(SLOT_2, RIGHT);
	Ultrason ultra(PORT6,5);
	Movements move(&mot1, &mot2);
	Gyroscope gyro(PORT_6, 3);
//	gyro.begin();
//	Pince pince(SLOT_4);

	Robot robot(gyro, move, ultra);

//	pince.close();
//	pince.open();


	//robot.doPath();	
	robot.turn90(RIGHT);
	robot.turn90(RIGHT);
	robot.turn90(LEFT);
	robot.turn90(LEFT);
	//robot.doPath();	

	while ( true ) {
		delay(300);
	}

	//move.forward(1);

	return 0;
}
