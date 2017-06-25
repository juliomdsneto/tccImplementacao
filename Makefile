COMPILER=g++
CPPFLAGS=-Wall -Werror -lgsl -lgslcblas -lm -fopenmp
SOURCEDIRS=lib/*.cpp src/*.cpp
OUTFILE=main

all:
	$(COMPILER) $(CPPFLAGS) $(SOURCEDIRS) -o build/$(OUTFILE)

run:
	GSL_RNG_SEED=$(date +%s%N) GSL_RNG_TYPE=mrg \
				 /usr/bin/time bin/main \
				 &>>logs/output`date +%y%m%d%H%M`.txt	
