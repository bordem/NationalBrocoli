#ifndef MOTOR
#define MOTOR

#include "MeEncoderOnBoard.h"
#include "types.h"

class Motor{
	private:
		MeEncoderOnBoard motor;
		const float correction;
		Pos position;
	public:
		Motor(uchar port,  Pos position );
		void backward(uchar speed);
		void forward(uchar speed);
		void stop();
};
#endif
