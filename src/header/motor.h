#ifndef DEF_MOTOR
#define DEF_MOTOR

#include <MeEncoderOnBoard.h>
#include "types.h"

class Motor{
	private:
		MeEncoderOnBoard& motor;
		float correction;
		char port;
		//Pos position;

	public:
		Motor(MeEncoderOnBoard motor,char port);
		//Motor(const Motor& M);
		void forward(char speed);
		void backward(char speed);

};
#endif /* end of include guard:  */
