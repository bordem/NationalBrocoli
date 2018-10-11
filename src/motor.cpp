#include "header/motor.h"

Motor::Motor(uint8_t p,Pos po):port(p),motor(p),position(po){
}

void Motor::stop(){
	motor.setMotorPwm(0);
}

void Motor::forward(char speed){
	if(position == gauche)
		motor.setMotorPwm(speed);
	else
		motor.setMotorPwm(-speed);
}

void Motor::backward(char speed){
	if(position == gauche)
		motor.setMotorPwm(-speed);
	else
		motor.setMotorPwm(speed);
}
long Motor::getPulse(){
	return motor.getPulsePos();
}
