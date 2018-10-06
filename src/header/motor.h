#pragma once

#include <MeEncoderOnBoard.h>

#include "types.h"

enum Pos{
	droite,
	gauche
};

class Motor{

	private:
		MeEncoderOnBoard motor;
		const float correction;
		const char port;
		Pos position;

	public:
		Motor(char port, Pos position);
		void forward(char speed);
		void backward(char speed);

};
