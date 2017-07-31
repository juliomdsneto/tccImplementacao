all:
	g++ -Ofast lib/*.cpp src/*.cpp -lgsl -lgslcblas -lm -fopenmp -o main_seq_Ofast
run:
	./main
