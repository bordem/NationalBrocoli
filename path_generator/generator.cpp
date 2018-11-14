#include "generator.h"
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

Generator::Generator(string path){
	using namespace std;
	this->file.open(path,ios::in);
	this->parse_file();
	cout << "#include \"robot.h\"" << endl;
	cout << "void Robot::doPath(){" << endl;
	this->generate();
	cout << "}" << endl; 
}

Generator::~Generator(){
	this->file.close();
}

#include <vector>

void orient(Direction start, Direction next){
	using namespace std;
	switch ( start ){
		case HAUT:{
			switch ( next ){
				case HAUT:{
					break;
				}
				case BAS: {
					cout << "\tmove.turn(RIGHT);" << endl;
					cout << "\tmove.turn(RIGHT);" << endl;
					break;
				}
				case DROITE:{
					cout << "\tmove.turn(RIGHT);" << endl;
					break;
				}
				case GAUCHE:{
					cout << "\tmove.turn(LEFT);" << endl;
					break;
				}
			}
			break;
		}
		case BAS:{
			switch ( next ){
				case HAUT:{
					cout << "\tmove.turn(RIGHT);" << endl;
					cout << "\tmove.turn(RIGHT);" << endl;
					break;
				}
				case BAS: {
					break;
				}
				case DROITE:{
					cout << "\tmove.turn(LEFT);" << endl;
					break;
				}
				case GAUCHE:{
					cout << "\tmove.turn(RIGHT);" << endl;
					break;
				}
			}
			break;
		}
		case DROITE:{
			switch ( next ){
				case HAUT:{
					cout << "\tmove.turn(LEFT);" << endl;
					break;
				}
				case BAS: {
					cout << "\tmove.turn(RIGHT);" << endl;
					break;
				}
				case DROITE:{
					break;
				}
				case GAUCHE:{
					cout << "\tmove.turn(RIGHT);" << endl;
					cout << "\tmove.turn(RIGHT);" << endl;
					break;
				}
			}
			break;
		}
		case GAUCHE:{
			switch ( next ){
				case HAUT:{
					cout << "\tmove.turn(RIGHT);" << endl;
					break;
				}
				case BAS: {
					cout << "\tmove.turn(LEFT);" << endl;
					break;
				}
				case DROITE:{
					cout << "\tmove.turn(RIGHT);" << endl;
					cout << "\tmove.turn(RIGHT);" << endl;
					break;
				}
				case GAUCHE:{
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
	Direction robot = HAUT;
	cout << "\tmove.forward(" << (int)BLOCK_SIZE << ");" << endl;
	for ( auto it=++(nodes.begin()); it != nodes.end(); it++){
		cerr << "//(" << (int)prev->x << ", " << (int)prev->y << ") -> (" << (int)it->x << ", " << (int)it->y << ")" << endl;
		Direction suiv = this->direction(*prev, *it);
		int distance = max(abs(it->x-prev->x), abs(it->y - prev->y));
		orient(robot, suiv);
		robot=suiv;
		cout << "\tmove.forward(" <<  distance * BLOCK_SIZE<< ");" << endl;
		prev=it;
	}
}

Direction Generator::direction(::pair<char> A, ::pair<char> B){
	int dx = A.x - B.x;	
	int dy = A.y - B.y;
	if ( dx > 0 ){
		return GAUCHE;
	}
	else if ( dx < 0 ) {
		return DROITE;
	}
	if ( dy < 0 ){
		return HAUT;
	}
	else {
		return BAS;
	}
}

void Generator::parse_file(){
	using namespace std;
	string line;
	while ( getline(file, line) ){
		size_t cur, old=0;
		cur = line.find(" ");
		assert(cur != string::npos);
		string pos1 = line.substr(old, cur+1);
		string pos2 = line.substr(cur+1, line.length());
		int a=atoi(pos1.c_str()),
			b=atoi(pos2.c_str());
		nodes.push_back(
			::pair<char>(a,b)
		);
	}

}
