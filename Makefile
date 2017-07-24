all:
	g++ -Wall -Werror -O2 -fcx-limited-range lib/*.cpp src/*.cpp -lgsl -lgslcblas -lm -fopenmp -o main_4

run:
	./main
