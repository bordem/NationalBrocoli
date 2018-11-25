#include "motor.h"

Motor::Motor(uchar port,  Pos position ):motor(port),position(position){

}
void Motor::forward(uchar speed){
	if(position = LEFT){
		motor.setMotorPwm(-200);
	}else{
		motor.setMotorPwm(200);
	}
}
void Motor::backward(uchar speed){
	if(position = LEFT){
		motor.setMotorPwm(200);
	}else{
		motor.setMotorPwm(-200);
	}
}
void Motor::stop(){
	motor.setMotorPwm(0);
}
