#ifndef DEF_ARM
#define DEF_ARM

#include <MeEncoderOnBoard.h>
#include "types.h"

class Arm{
	private:
		MeEncoderOnBoard motor;
		uint8_t port;

	public:
		Arm(uint8_t port);
		void up();
		void down();
		void down(int);
		void up(int);
		void stop();
};
#endif
