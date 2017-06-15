all:
	g++  *.cpp -fpermissive  lib/*.cpp -lgsl -lgslcblas -lm  -o main
	
