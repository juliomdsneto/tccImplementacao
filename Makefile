all:
	g++  *.cpp -Wall -Werror  lib/*.cpp -lgsl -lgslcblas -lm -fopenmp  -o main

run:
	./run.sh	
