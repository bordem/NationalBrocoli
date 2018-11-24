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
enum Direction{
	DROITE,
	GAUCHE,
	HAUT,
	BAS
};

class Generator{
 public:
	Generator(std::string path);
	~Generator();
	void generate();
	Direction direction(::pair<int> A, ::pair<int> B);

 private:
	std::fstream file;
	void parse_file();	
	std::vector<::pair<int>> nodes;
	const double BLOCK_SIZE=0.4;
};
