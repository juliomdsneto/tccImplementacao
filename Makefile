all:
	g++ -Wall -Werror -O3 -fcx-limited-range lib/*.cpp src/*.cpp -lgsl -lgslcblas -lm -fopenmp -o main_seq

run:
	./main
