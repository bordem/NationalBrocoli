#ifndef DEF_MOTOR
#define DEF_MOTOR

#include <MeEncoderOnBoard.h>
#include "types.h"

class Motor{
	private:
		MeEncoderOnBoard motor;
		float correction;
		uint8_t port;
		Pos position;

	public:
		Motor(uint8_t port, Pos p);
		//Motor(const Motor& M);
		void stop();
		void forward(uchar speed=200);
		void backward(uchar speed=200);
		long getPulse();

};
#endif /* end of include guard:  */
