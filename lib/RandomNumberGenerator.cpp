#include "RandomNumberGenerator.hpp"
#include <gsl/gsl_rng.h>
#include <gsl/gsl_math.h>
#include <iostream>	
unsigned long int RandomNumberGenerator::random(){

	return this->gnuUniformRandomGenerator(1234567890);
}

unsigned long int RandomNumberGenerator::gnuUniformRandomGenerator(unsigned long int seed){
	
	const gsl_rng_type* T;
	gsl_rng* r;

	int n = 5;

	gsl_rng_env_setup();

	T = gsl_rng_default;
	r = gsl_rng_alloc(T);

	unsigned long int uniformValue = 0;

	for(int i = 0; i < n; i++){
	
		double uniformSeq = gsl_rng_uniform (r);

		std::cout  << "valor: "<< uniformValue << std::endl;

		uniformValue = uniformValue * 100;
	}
	
	gsl_rng_free(r);
	
	return ;
}
