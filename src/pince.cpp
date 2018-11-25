#include "pince.h"

Pince::Pince(uint8_t port):motor(port){
	
}

void Pince::close(){
	motor.setMotorPwm(-150);
}
void Pince::open(){
	motor.setMotorPwm(150);
}
void Pince::stop(){
	motor.setMotorPwm(0);
}
void Pince::close(float temps){
	motor.setMotorPwm(-150);
	delay(temps*1000);
	motor.setMotorPwm(0);
}
void Pince::open(float temps){
	motor.setMotorPwm(150);
	delay(temps*1000);
	motor.setMotorPwm(0);
}
