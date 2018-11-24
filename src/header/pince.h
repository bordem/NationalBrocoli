#ifndef DEF_PINCE
#define DEF_PINCE

#include <MeEncoderOnBoard.h>
#include "types.h"

class Pince{
	private:
		MeEncoderOnBoard motor;
		uint8_t port;

	public:
		Pince(uint8_t port);
		void close();
		void open();
};
#endif
