#ifndef DEF_MOTOR
#define DEF_MOTOR

#include "../../lib/MakeBlockDrive/src/MeEncoderOnBoard.h"

enum pos{
	droite,
	gauche
};

class Motor{

	private:
		MeEncoderOnBoard motor;
		float correction;
		char port;
		pos position;

	public:
		Motor(char port,pos position,float correction);
		void forward(char speed);
		void backward(char speed);

};
#endif /* end of include guard:  */
