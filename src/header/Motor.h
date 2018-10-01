#pragma once

class Motor{

	enum pos{
		droite,
		gauche
	}

	private:
		MeEncoderOnBoard motor;
		const float correction;
		pos position;

	public:
		void forward(char speed);
		void backward(char speed);


};
