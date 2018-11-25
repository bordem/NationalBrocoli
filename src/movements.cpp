#include <movements.h>


Movements::Movements(uchar portML, uchar portMR)
	motorL(portML, LEFT),
	motorR(portMR, RIGHT)
{}



void Movements::getSpeed() const {
	return speed;
}

void Movements::turn90(Pos dir, uchar speed){
	if ( dir == LEFT ){
		motorL.forward(speed);
		motorR.forward(speed);
	}
	else {
		motorR.forward(speed);
		motorL.forward(speed);
	}
}

void Movement::stop(){
	motorR.stop();
	motorL.stop();
}

void Movement::goAt(uchar speedL, uchar speedR){
	motorL.forward(speedL);
	motorR.forward(speedR);
}

void Movements::backward(float distance){
	int time = distance * this->getSpeed(); 
	int start_time = millis();
	uchar speed = 200;
	motorR.backward(speed);
	motorL.backward(speed);
	while ( ( millis() - start_time ) < time );
	this->stop();
}

void Movements::foraward(float distance, Ultrasound ultra, Gyroscope gyro){
	int time = distance * this->getSpeed(); 
	int start_time = millis();
	uchar speed = 200;
	int correction=30;
	while ( ( millis() - start_time ) < time ){

		if ( ultra.obstacleAt(10) ){
			break;
		}
		
		int distance = gyro.getAngle();

		if ( distance < 0 && distance > -3 ){
			motorL.forward(speed+correction);
			motorR.forward(speed-correction);
		}
		else if ( distance > 0 && distance < 3 ){
			motorL.forward(speed-correction);
			motorR.forward(speed+correction);
		}
		else {
			motorL.forward(speed);
			motorR.forward(speed);
		}
	}
	this->stop();
}
