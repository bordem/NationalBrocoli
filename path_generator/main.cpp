#include <iostream>
#include "generator.h"

#include <string>


using namespace std;

int main(int argc, char* argv[]){
	string nom = "terrain.txt";
	if ( argc > 1 ){
		nom = string(argv[1]);
	}
	Generator gen(nom);
}
