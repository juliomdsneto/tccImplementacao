#include "RandomNumberGenerator.hpp"
#include "q_projectiveMeasure.hpp"
#include <iostream>	
#include <sys/time.h>
void q_projectiveMeasure(float complex *state, int numqubits, std::vector<int> qubits_to_measure){

	std::map<int,float> mapping;
	std::pair<std::map<int,float>::iterator,bool> aux;

	int iterations = pow(2, numqubits);
	int mask = 0;
	int measured_index;

	
	float normalization;
	float * tmp = new float[iterations];
	float acumulador = 0;

	//TIME

	for(unsigned int i = 0; i < qubits_to_measure.size(); i++)
		mask = mask | 1 << (numqubits - qubits_to_measure[i] - 1);



	RandomNumberGenerator* randomGen = new RandomNumberGenerator();

#pragma omp parallel for num_threads(4) 
	for (int i = 0 ; i < iterations ; i++){
		tmp[i] = pow(crealf(state[i]), 2) + pow(cimagf(state[i]), 2);
	}

	for (int i = 0 ; i < iterations ; i++){
		mapping[mask & i] += tmp[i];

	}


	// for (int i = 0 ; i < iterations ; i++){
	// 	mapping[mask & i] += pow(crealf(state[i]), 2) + pow(cimagf(state[i]), 2);
	// }


	// for (std::map<int, float>::iterator it=mapping.begin(); it!=mapping.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

	unsigned long int generatedValue = randomGen->random();
	for(std::map<int, float>::iterator it=mapping.begin(); it!=mapping.end(); ++it) {

		acumulador += it->second * 1000;

		if(generatedValue < acumulador){
			measured_index = it->first;
			normalization = it->second;
			break;
		}

	 }

//	 std::cout << "Generated_Value: " << generatedValue << std::endl; // valor gerado no random
#pragma omp parallel for num_threads(4)
	for (int i =0; i < iterations; i++) {
		if((mask & i) == measured_index) {
			state[i] = state[i]/sqrt(normalization);
		}
		else {			
			state[i] = 0;			
		}
	}
	delete(tmp);
}	
