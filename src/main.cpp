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
	Ultrason ultraLeft(PORT_6,5);
	Ultrason ultraRight(PORT_8,5);
	Movements move(&mot1, &mot2);
	Gyroscope gyro(PORT_7, 3);
//	gyro.begin();
//	Pince pince(SLOT_4);

	Robot robot(gyro, move, ultraLeft, ultraRight);

	robot.doPath();

	while ( true ){
		Serial.println(gyro.getAngle());
		delay(100);
	}

	//move.forward(1);

	return 0;
}
