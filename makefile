O:
	@g++ -std=c++11 -Wall -O3 src/*.cpp -I include/ -o bin/main -lpthread
G:
	@g++ -std=c++11 -Wall -g -O0 src/*.cpp -I include/ -o bin/main -lpthread
