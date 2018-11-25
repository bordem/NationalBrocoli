#pragma once
#include <vector>
#include <fstream>

enum Direction {
	DROITE, 
	GAUCHE, 
	HAUT,
	BAS
};

struct pair {
	int x;
	int y;
};

class Generator {
 public:
	Generator(std::string path);
	~Generator();
	void generate();
 private:
	Direction direction(::pair A, ::pair B);
	void parse_file();
	std::vector<::pair> nodes;
	std::fstream file;
	int BLOCK_SIZE=40;
};
