#include <Arduino.h>
#include <MeMegaPi.h>
#include <robot.h>


int main(){
	init();
	Serial.begin(115200);
	Robot robot(PORT_7, PORT_6, SLOT_1, SLOT_2);
	robot.doPath();
	while (true);
	return 0;
}
