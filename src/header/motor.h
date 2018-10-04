#pragma once

class Motor{

	private:
		MeEncoderOnBoard motor;
		const float correction;
		const char port;
		pos position;

	public:
		Motor(char port,pos position);
		void forward(char speed);
		void backward(char speed);

		enum pos{
			droite,
			gauche
		}
};
