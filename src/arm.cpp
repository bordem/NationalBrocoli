#include <arm.h>

Arm::Arm(uint8_t port):motor(port){}
void Arm::up(){
	motor.setMotorPwm(150);
}
void Arm::down(){
	motor.setMotorPwm(-150);
}
void Arm::stop(){
	motor.setMotorPwm(0);
}
void Arm::up(int temps){
	motor.setMotorPwm(150);
	delay(temps);
	motor.setMotorPwm(0);
}
void Arm::down(int temps){
	motor.setMotorPwm(-150);
	delay(temps);
	motor.setMotorPwm(0);
}
