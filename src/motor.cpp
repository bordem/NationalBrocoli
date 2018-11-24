#include "header/motor.h"

Motor::Motor(uint8_t p,Pos po):port(p),motor(p),position(po){
	if(position == RIGHT)
		correction=5;
}

void Motor::stop(){
	motor.setMotorPwm(0);
}

void Motor::forward(uchar speed){
	if(position == RIGHT)
		motor.setMotorPwm(speed+correction);
	else
		motor.setMotorPwm(-speed);
}

void Motor::backward(uchar speed){
	if(position == RIGHT)
		motor.setMotorPwm(-speed-correction);
	else
		motor.setMotorPwm(speed);
}
long Motor::getPulse(){
	return motor.getPulsePos();
}
