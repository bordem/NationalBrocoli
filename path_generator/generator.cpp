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
#include <vector>

void orient(Generator::Direction start, Generator::Direction next){
	using namespace std;
	switch ( start ){
		case Generator::HAUT:{
			switch ( next ){
				case Generator::HAUT:{
					break;
				}
				case Generator::BAS: {
					cout << "TOURNER DROITE TOURNER DROITE" << endl;
					break;
				}
				case Generator::DROITE:{
					cout << "TOURNER DROITE" << endl;
					break;
				}
				case Generator::GAUCHE:{
					cout << "TOURNER GAUCHE" << endl;
					break;
				}
			}
			break;
		}
		case Generator::BAS:{
			switch ( next ){
				case Generator::HAUT:{
					cout << "TOURNER DROITE TOURNER DROITE" << endl;
					break;
				}
				case Generator::BAS: {
					break;
				}
				case Generator::DROITE:{
					cout << "TOURNER GAUCHE" << endl;
					break;
				}
				case Generator::GAUCHE:{
					cout << "TOURNER DROITE" << endl;
					break;
				}
			}
			break;
		}
		case Generator::DROITE:{
			switch ( next ){
				case Generator::HAUT:{
					cout << "TOURNER GAUCHE" << endl;
					break;
				}
				case Generator::BAS: {
					cout << "TOURNER DROITE" << endl;
					break;
				}
				case Generator::DROITE:{
					break;
				}
				case Generator::GAUCHE:{
					cout << "TOURNER DROITE TOURNER DROITE" << endl;
					break;
				}
			}
			break;
		}
		case Generator::GAUCHE:{
			switch ( next ){
				case Generator::HAUT:{
					cout << "TOURNER DROITE" << endl;
					break;
				}
				case Generator::BAS: {
					cout << "TOURNER GAUCHE" << endl;
					break;
				}
				case Generator::DROITE:{
					cout << "TOURNER DROITE TOURNER DROITE" << endl;
					break;
				}
				case Generator::GAUCHE:{
					break;
				}
			}
			break;
		}
	}
}

int abs(int a){
	if ( a < 0 ) return -a;
	return a;
}

void Generator::generate(){
	using namespace std;
	auto prev=nodes.begin();
	Direction robot = Direction::HAUT;
	cout << "1 AVANCER " << endl;
	for ( auto it=++(nodes.begin()); it != nodes.end(); it++){
		cerr << "(" << (int)prev->x << ", " << (int)prev->y << ") -> (" << (int)it->x << ", " << (int)it->y << ")" << endl; // ne marche pas bizarrement
		Direction suiv = this->direction(*prev, *it);
		int distance = max(abs(it->x-prev->x), abs(it->y - prev->y));
		orient(robot, suiv);
		robot=suiv;
		cout << "\t" <<  distance << " AVANCER" << endl;
		prev=it;
	}
}

Generator::Direction Generator::direction(::pair<char> A, ::pair<char> B){
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
			::pair<char>(a,b)
		);
	}

}
