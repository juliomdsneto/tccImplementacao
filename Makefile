all:
	g++ -Wall -Werror lib/*.cpp src/*.cpp -lgsl -lgslcblas -lm -fopenmp  -o main2

run:
	./main
