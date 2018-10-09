#include "header/motor.h"

<<<<<<< HEAD
using namespace std;
// Motor::Motor(const Motor& M): motor(M.motor),correction(M.correction),port(M.port)
// {}
=======

//Motor::Motor(const Motor& M): motor(M.motor),correction(M.correction),port(M.port)
//{}
>>>>>>> 2f932dcb6804c719702ea96af039780860e950fb

Motor::Motor(MeEncoderOnBoard motor,char p):motor(motor),port(p)
{}

void Motor::forward(char speed){

}
void Motor::backward(char speed){
}
