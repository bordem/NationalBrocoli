#include "pince.h"

Pince::Pince(uint8_t port):motor(port){}

void Pince::close(){
	motor.setMotorPwm(-200);
	delay(1000);
	motor.setMotorPwm(0);
}
void Pince::open(){
	motor.setMotorPwm(200);
	delay(1000);
	motor.setMotorPwm(0);
}
