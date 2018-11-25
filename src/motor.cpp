#include "motor.h"

Motor::Motor(uchar port,  Pos position ):motor(port),position(position){

}
void Motor::forward(uchar speed){
	if(position == LEFT){
		motor.setMotorPwm(-speed);
	}else{
		motor.setMotorPwm(speed);
	}
}
void Motor::backward(uchar speed){
	if(position == LEFT){
		motor.setMotorPwm(speed);
	}else{
		motor.setMotorPwm(-speed);
	}
}
void Motor::stop(){
	motor.setMotorPwm(0);
}
