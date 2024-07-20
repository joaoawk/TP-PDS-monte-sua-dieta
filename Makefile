all: build/main.o build/login.o build/menu.o
	g++ build/main.o build/login.o build/menu.o -o dieta

build/main.o: main.cpp include/*.hpp
	g++ -c -o build/main.o main.cpp

build/login.o: src/login.cpp include/login.hpp
	g++ -c -o build/login.o src/login.cpp
	
build/menu.o: src/menu.cpp include/menu.hpp
	g++ -c -o build/menu.o src/menu.cpp