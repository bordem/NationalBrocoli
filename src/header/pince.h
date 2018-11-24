#ifndef DEF_PINCE
#define DEF_PINCE

#include <MeEncoderOnBoard.h>
#include "types.h"

class Pince{
	private:
		MeEncoderOnBoard motor;

	public:
		Pince(uint8_t port=4);
		void close();
		void open();
};
#endif
