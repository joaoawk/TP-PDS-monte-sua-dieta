OUTPUT_DIR := build

all: $(OUTPUT_DIR) build/main.o build/Login.o build/Menu.o build/DietProfiles.o
	g++ build/main.o build/Login.o build/Menu.o build/DietProfiles.o -o dieta

$(OUTPUT_DIR):
	@if [ ! -d "$(OUTPUT_DIR)" ]; then \
		mkdir $(OUTPUT_DIR); \
	fi

build/main.o: main.cpp include/*.hpp | $(OUTPUT_DIR)
	g++ -c -o build/main.o main.cpp

build/Login.o: src/Login.cpp include/Login.hpp | $(OUTPUT_DIR)
	g++ -c -o build/Login.o src/Login.cpp
	
build/Menu.o: src/Menu.cpp include/Menu.hpp | $(OUTPUT_DIR)
	g++ -c -o build/Menu.o src/Menu.cpp

build/DietProfiles.o: src/DietProfiles.cpp include/DietProfiles.hpp | $(OUTPUT_DIR)
	g++ -c -o build/DietProfiles.o src/DietProfiles.cpp
