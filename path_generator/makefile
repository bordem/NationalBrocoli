#$@	Le nom de la cible
#$<	Le nom de la première dépendance
#$^	La liste des dépendances
#$?	La liste des dépendances plus récentes que la cible
#$*	Le nom du fichier sans suffixe

CXX=g++
CXXFLAGS= -std=c++14 -ggdb -fno-stack-protector
LDFLAGS=
EXEC=generator
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=obj/%.o)

all: init $(EXEC)

init:
	mkdir -p obj

$(EXEC): $(OBJ)
	@$(CXX) -o $@ $^ $(LDFLAGS)
	@echo "Linking $^"

obj/%.o: %.cpp
	@$(CXX) -o $@ -c $^ $(CXXFLAGS)
	@echo "Compiling $^ -> $<"

.PHONY: clean mrproper

clean:
	rm obj/*.o
	rm $(EXEC)
