#ifndef PINCE
#define PINCE

#include "MeEncoderOnBoard.h"

class Pince{
	private:
		MeEncoderOnBoard motor;
	public:
		Pince(uint8_t port);
		void open();
		void close();
		void stop();
		void open(float);
		void close(float);
};
#endif
