#pragma once

#include <vector>

class Gyroscope{
	private:
		std::vector<uchar> ports;
		std::vector<MeGyro> sensor;
		const int gyro_nb;
		const int iterations;

	public:
		Gyroscope(std::vector<uchar> port, int max_iter);
		void reset();
		unsigned double angle();
};
