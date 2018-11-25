#include <movements.h>


Movements::Movements(uchar portML, uchar portMR):
	motorL(portML, LEFT),
	motorR(portMR, RIGHT)
{}



float Movements::getSpeed() const {
	return speed;
}

void Movements::turn90(Pos dir, uchar speed){
	if ( dir == RIGHT ){
		motorL.forward(speed);
		motorR.backward(speed);
	}
	else {
		motorR.forward(speed);
		motorL.backward(speed);
	}
}

void Movements::stop(){
	motorR.stop();
	motorL.stop();
	Serial.println("STOP");
}

void Movements::goAt(uchar speedL, uchar speedR){
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

void Movements::forward(float distance, Ultrasound ultra, Gyroscop gyro){
	Serial.println("Avancer");
	unsigned int time = distance / this->getSpeed() * 1000;
	uchar speed = 200;
	int correction=30;
	unsigned int start_time = millis();
	while ( ( millis() - start_time ) < time ){

		if ( ultra.obstacleAt(10) ){
			break;
		}

		int angle = gyro.getAngle();

		if ( angle < 0 ){
			Serial.println("GAUCHE");
			motorL.forward(speed-correction);
			motorR.forward(speed+correction);
		}
		else if ( angle > 0 ){
			Serial.println("DROITE");
			motorL.forward(speed+correction);
			motorR.forward(speed-correction);
		}
		else {
			Serial.println("NORMAL");
			motorL.forward(speed);
			motorR.forward(speed);
		}
	}
	this->stop();
}



void Movements::calcSpeed(Ultrasound ultra, Gyroscop gyro){
	int start_time = millis();
	int distance = ultra.readDistance() -10;
	int correction = 30;
	int speed = 200;
	while ( ! ultra.obstacleAt(10) ){
		int angle = gyro.getAngle();
		if ( angle < 0 ){
			motorL.forward(speed-correction);
			motorR.forward(speed+correction);
		}
		else if ( angle > 0 ){
			motorL.forward(speed+correction);
			motorR.forward(speed-correction);
		}
		else {
			motorL.forward(speed);
			motorR.forward(speed);
		}
	}
	motorL.stop();
	motorR.stop();
	int time = millis() - start_time;
	float speedCalc = distance / ( (float) time / 1000);
}
