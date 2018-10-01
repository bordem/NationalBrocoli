#pragma once
class Ultrason{
	private:
		MeUltrasonicSensor sensor;
		const int iterations;
		int port;
		
	public:
		Ultrason(int port, int max_iter);
		float readDistance(int n=1);
		bool obstacleAt(float n);
};
