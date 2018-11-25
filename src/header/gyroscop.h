#pragma once
#include <MeGyro.h>
#include <types.h>

class Gyroscop {
 private:
	MeGyro sensor;
	const int iterations;
 public:
	Gyroscop(uchar port, int max_iter);
	void begin();
	void update();
	double getAngle();
};
