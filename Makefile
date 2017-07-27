all:
	g++   lib/*.cpp src/*.cpp -lgsl -lgslcblas -lm -fopenmp -o main_seq_sem_flags

run:
	./main
