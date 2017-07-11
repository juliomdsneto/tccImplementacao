#include "RandomNumberGenerator.hpp"
#include "q_projectiveMeasure.hpp"
#include <iostream>	

void q_projectiveMeasure(float complex *state, int numqubits, std::vector<int> qubits_to_measure){

	std::map<int,float> mapping;
	std::pair<std::map<int,float>::iterator,bool> aux;

	int iterations = pow(2, numqubits);
	int mask = 0;

	float * tmp = new float[iterations];
	float acumulador = 0;

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

	for (std::map<int, float>::iterator it=mapping.begin(); it!=mapping.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	unsigned long int generatedValue = randomGen->random();

	for(std::map<int, float>::iterator it=mapping.begin(); it!=mapping.end(); ++it) {

		acumulador += it->second * 1000;

		if(generatedValue < acumulador){
//			std::cout << "index: " << it->first << std::endl; // indice
			std::cout << "measure result: " << it->second << std::endl; // measure
			break;
		}

	 }


	 std::cout << "Generated_Value: " << generatedValue << std::endl; // valor gerado no random



		for (std::map<int, float>::iterator it=mapping.begin(); it!=mapping.end(); ++it) {
			if(mask == it->first) {
				it->second = it->second/sqrt(it->second);
			} else {
				it->second = 0;			
			}
		}
		delete(tmp);
}
