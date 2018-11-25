#include "generator.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Generator::Generator(string path){
	file.open(path, ios::in);
	this->parse_file();
	cout << "#include <robot.h>" << endl;
	cout << endl << "void Robot::doPath(){" << endl;
	cout << "\tgyro.begin();" << endl;
	cout << "\tmove.forward("<<BLOCK_SIZE << ", ultra, gyro);" << endl;
	this->generate();
	cout << "}" << endl;
}

Generator::~Generator(){
	file.close();
}

void Generator::parse_file(){
	string line;
	while ( getline(file, line) ){
		size_t cur = line.find(" ");
		string coord1 = line.substr(0, cur+1);
		string coord2 = line.substr(cur+1, line.length());
		nodes.push_back((::pair){
			atoi(coord1.c_str()), 
			atoi(coord2.c_str())
		});
	}
}

void orient(Direction robot, Direction next){
	switch ( robot ){
		case HAUT:
			switch ( next ){
				case BAS:
					cout << "\tthis->turn90(RIGHT);" << endl;
					cout << "\tthis->turn90(RIGHT);" << endl;
				break;
				case DROITE:
					cout << "\tthis->turn90(RIGHT);" << endl;
				break;
				case GAUCHE:
					cout << "\tthis->turn90(LEFT);" << endl;
				break;
			}
		break;
		case BAS:
			switch ( next ){
				case HAUT:
					cout << "\tthis->turn90(RIGHT);" << endl;
					cout << "\tthis->turn90(RIGHT);" << endl;
				break;
				case DROITE:
					cout << "\tthis->turn90(LEFT);" << endl;
				break;
				case GAUCHE:
					cout << "\tthis->turn90(RIGHT);" << endl;
				break;
			}
		break;
		case DROITE:
			switch ( next ){
				case HAUT:
					cout << "\tthis->turn90(LEFT);" << endl;
				break;
				case BAS:
					cout << "\tthis->turn90(RIGHT);" << endl;
				break;
				case GAUCHE:
					cout << "\tthis->turn90(RIGHT);" << endl;
					cout << "\tthis->turn90(RIGHT);" << endl;
				break;
			}
		break;
		case GAUCHE:
			switch ( next ){
				case HAUT:
					cout << "\tthis->turn90(RIGHT);" << endl;
				break;
				case BAS:
					cout << "\tthis->turn90(LEFT);" << endl;
				break;
				case DROITE:
					cout << "\tthis->turn90(RIGHT);" << endl;
					cout << "\tthis->turn90(RIGHT);" << endl;
				break;
			}
		break;
	}
}

int abs(int a){
	return a<0? -a: a;
}

Direction Generator::direction(::pair A, ::pair B){
	int dx = A.x - B.x;
	int dy = A.y - B.y;

	if ( dx > 0 ){
		return GAUCHE;	
	}
	else if ( dx < 0 ){	
		return DROITE;
	}
	if ( dy > 0 ){
		return BAS;
	}
	else{
		return HAUT;
	}
}

void Generator::generate(){
	Direction robot=HAUT;
	for ( auto it=++nodes.begin(); it != nodes.end(); it++ ){
		cerr << "\t//(" << (it-1)->x << ", " << (it-1)->y << ") -> (" << it->x << ", " << it->y << ")" << endl;
		::pair currPoint = *(it-1);
		::pair nextPoint = *(it);
		Direction next = direction(currPoint, nextPoint);
		orient(robot, next); 
		robot=next;
		int distance = abs((currPoint.x - nextPoint.x) + ( currPoint.y - nextPoint.y ));
		cout << "\tgyro.begin();" << endl;
		cout << "\tmove.forward(" << BLOCK_SIZE*distance << ", ultra, gyro);" << endl;
	}
}
