all:
	@g++ -std=c++11 -Wall -O3 src/*.cpp -I include/ -o bin/main
