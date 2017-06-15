#include "RandomNumberGenerator.hpp"
#include <gsl/gsl_rng.h>
#include <gsl/gsl_math.h>
unsigned long int RandomNumberGenerator::random()
{
	return this->gnuUniformRandomGenerator(1234567890);
}

unsigned long int RandomNumberGenerator::gnuUniformRandomGenerator(unsigned long int seed)
{
	const gsl_rng_type* T;
	gsl_rng* r;

	gsl_rng_env_setup();

	T = gsl_rng_default;
	r = gsl_rng_alloc(T);
	double urologista = gsl_rng_uniform (r);

	unsigned long int banana = urologista * 100;
	gsl_rng_free(r);
	return banana;
}
