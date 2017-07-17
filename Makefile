all:
	g++ -Wall -Werror lib/*.cpp src/*.cpp -lgsl -lgslcblas -lm  -o main_seq

run:
	./main
