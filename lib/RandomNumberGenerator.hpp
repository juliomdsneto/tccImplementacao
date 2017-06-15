#include <cstdio>
#include <cstdlib>
#include <gsl/gsl_rng.h>
#define HIGHEST_INT_FOR_RANDOM 10000

class RandomNumberGenerator
{
	public:
	unsigned long int seed;
	char randomFunction;

	RandomNumberGenerator()
	{
		this->seed = 123456789;
		this->randomFunction = 0;
	}

	public:
	unsigned long int random();
	unsigned long int gnuUniformRandomGenerator(unsigned long int seed);
};
