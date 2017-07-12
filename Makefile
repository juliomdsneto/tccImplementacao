all:
	g++ -Wall -Werror lib/*.cpp src/*.cpp -lgsl -lgslcblas -lm -fopenmp  -o main_2

run:
	./main
