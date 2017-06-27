COMPILER=g++
CPPFLAGS=-Wall -Werror -lgsl -lgslcblas -lm -fopenmp
SOURCEDIRS=lib/*.cpp src/*.cpp
OUTFILE=main

SEED=`date +%s%N`
RNG_TYPE=mrg


all:
	$(COMPILER) $(SOURCEDIRS) $(CPPFLAGS) -o build/$(OUTFILE)
	cp build/main bin/

run:
	export GSL_RNG_SEED=$(SEED)
	export GSL_RNG_TYPE=$(RNG_TYPE)
	bin/main  >logs/output`date +%y%m%d%H%M`.txt 
