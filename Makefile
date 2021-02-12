# Used for compiling the program with all the SFML libs.

# Vars
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
PROGRAM_NAME = traffic-sim

# Compile all
all: build


# Create needed directories
dirs:
	mkdir -p build/


# Compile and link the program with SFML
build: dirs main.cpp
	g++ main.cpp ${LINKER_FLAGS} -o build/${PROGRAM_NAME}


# Run the program using make `make run`
run: build
	./build/${PROGRAM_NAME}