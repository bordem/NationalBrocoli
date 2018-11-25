#pragma once
#include <types.h>
#include <motor.h>
#include <ultrasound.h>
#include <gyroscope.h>

class Movements {
 private:
	Motor motorLeft:
	Motor motorRight;
	static const float speed=42;

 public:
	Movements(uchar portML, uchar portMR);
	void backward(float distance);
	void forward(float distance, Ultrasound ultra, Gyroscope gyro);
	void stop();
	static void getSpeed() const;
	void goAt(uchar speedL, uchar speedR);
	void turn90(Pos dir, uchar speed=200);
};
