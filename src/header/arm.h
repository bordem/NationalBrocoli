#ifndef ARM
#define ARM

#include "MeEncoderOnBoard.h"

class Arm{
	private:
		MeEncoderOnBoard motor;
	public:
		Arm(uint8_t port);
		void up();
		void down();
		void stop();
		void up(int);
		void down(int);
};
#endif
