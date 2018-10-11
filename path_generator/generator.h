#pragma once 
#include <vector>
#include <fstream>
#include "../src/header/types.h"

template<typename T>
struct pair{
	pair<T>(T a, T b){x=a,y=b;}
	T x;
	T y;
};

class Generator{
 public:
	Generator(std::string path);
	~Generator();
	void generate();
	enum Direction{
		DROITE,
		GAUCHE,
		HAUT,
		BAS
	};
	Direction direction(::pair<uchar> A, ::pair<uchar> B);

 private:
	std::fstream file;
	void parse_file();	
	std::vector<::pair<uchar>> nodes;
};
