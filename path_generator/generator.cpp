#include "generator.h"
#include <cassert>
#include <cstdlib>

using namespace std;

Generator::Generator(string path){
	this->file.open(path,ios::in);
	this->parse_file();
	this->generate();
}

Generator::~Generator(){
	this->file.close();
}

#include <iostream>
void Generator::generate(){
	using namespace std;
	auto prev=nodes.begin();
	for ( auto it=++(nodes.begin()); it != nodes.end(); it++){
		cerr << "(" << prev->x << ", " << prev->y << ") -> (" << it->x << ", " << it->y << ")"; // ne marche pas bizarrement
		switch (this->direction(*prev, *it) ){
		case HAUT:
			cout << "HAUT" << endl;
			break;
		case BAS:
			cout << "BAS" << endl;
			break;
		case GAUCHE:
			cout << "GAUCHE" << endl;
			break;
		case DROITE:
			cout << "DROITE" << endl;
			break;
		default:
			abort();
		}
		prev=it;
	}
}

Generator::Direction Generator::direction(::pair<uchar> A, ::pair<uchar> B){
	int dx = A.x - B.x;	
	int dy = A.y - B.y;
	if ( dx > 0 ){
		return Direction::GAUCHE;
	}
	else if ( dx < 0 ) {
		return Direction::DROITE;
	}
	if ( dy < 0 ){
		return Direction::HAUT;
	}
	else {
		return Direction::BAS;
	}
}

void Generator::parse_file(){
	using namespace std;
	string line;
	while ( getline(file, line) ){
		size_t cur, old=0;
		cur = line.find(" ");
		assert(cur != string::npos);
		string name = line.substr(old, cur);
		old = cur;
		cur = line.find(" ", cur+1);
		assert(cur != string::npos);
		string pos1 = line.substr(old, cur+1);
		string pos2 = line.substr(cur+1, line.length());
		int a=atoi(pos1.c_str()),
			b=atoi(pos2.c_str());
		cerr << name << "-> a: " <<a << ", b=" << b << endl;
		nodes.push_back(
			::pair<uchar>(a,b)
		);
	}

}
