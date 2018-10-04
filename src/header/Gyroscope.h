#pragma once

#include <vector>

class Gyroscope{
	private:
		vector<uchar> ports;
		vector<MeGyro> sensor;
		const int gyro_nb;
		const int iterations;

	public:
		Gyroscope(vector<uchar> port, int max_iter);
		void reset();
		unsigned double angle();
};
