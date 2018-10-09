#include <iostream>
#include "generator.h"
#include <cstring>

int main(int argc, char* argv[]){
	char* path = NULL;
	if ( argc > 1 ){
		path = strdup(argv[1]);
	}
	else {
		path=strdup("terrain.txt");
	}
	Generator gen(path);
	return 0;
}
