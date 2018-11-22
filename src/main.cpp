#include <MeMegaPi.h>
#include <Arduino.h>
#include <Wire.h>
#include <movements.h>
#include <ultrasound.h>
#include <gyroscop.h>
#include <robot.h>
#include <camera.h>
#include <pince.h>

int main(void ){
	init();
	Serial.begin(115200);

	Motor mot1(SLOT_1, LEFT);
	Motor mot2(SLOT_2, RIGHT);
	Ultrasound ultra(PORT_6,11);
	Movements move(&mot1, &mot2);
	Gyroscop gyro(PORT_7, 3);
//	gyro.begin();
//	Pince pince(SLOT_4);

	Robot robot(gyro, move, ultra);

	robot.doPath();

	while ( true ){
/*		Serial.print("( ");
		Serial.print(ultraLeft.readDistance());
		Serial.print(", ");
		Serial.print(ultraRight.readDistance());
		Serial.println(" )");
	//	Serial.println(gyro.getAngle());
		delay(500);*/
	}


	return 0;
}
