#include "header/motor.h"


//Motor::Motor(const Motor& M): motor(M.motor),correction(M.correction),port(M.port)
//{}

Motor::Motor(MeEncoderOnBoard motor,char p):motor(motor),port(p)
{
}

void Motor::forward(char speed){

}
void Motor::backward(char speed){
}
