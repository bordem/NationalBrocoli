#include "arm.h"
#include "ultrasound.h"

Arm::Arm(uint8_t port):motor(port){
}
void Arm::up(){
	motor.setMotorPwm(-200);
	delay(1000);
	motor.setMotorPwm(0);
}
void Arm::down(){
	motor.setMotorPwm(200);
	delay(1000);
	motor.setMotorPwm(0);
}
void Arm::down(int temps){
	motor.setMotorPwm(200);
	delay(temps);
	motor.setMotorPwm(0);
}
