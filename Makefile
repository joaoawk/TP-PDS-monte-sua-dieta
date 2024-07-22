all: build/main.o build/usuario.o build/menu.o
	g++ build/main.o build/usuario.o build/menu.o -o dieta

build/main.o: main.cpp include/*.hpp
	g++ -c -o build/main.o main.cpp

build/usuario.o: src/usuario.cpp include/usuario.hpp
	g++ -c -o build/usuario.o src/usuario.cpp
	
build/menu.o: src/menu.cpp include/menu.hpp
	g++ -c -o build/menu.o src/menu.cpp