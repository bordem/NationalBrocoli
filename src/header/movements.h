#pragma once
#include <types.h>
#include <motor.h>
#include <ultrasound.h>
#include <gyroscop.h>

class Movements {
 private:
	Motor motorL;
	Motor motorR;
	const float speed=42;

 public:
	Movements(uchar portML, uchar portMR);
	void backward(float distance);
	void forward(float distance, Ultrasound ultra, Gyroscop gyro);
	void stop();
	float getSpeed() const;
	void goAt(uchar speedL, uchar speedR);
	void turn90(Pos dir, uchar speed=200);
};
