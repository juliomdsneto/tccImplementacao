#include "RandomNumberGenerator.hpp"
#include "q_projectiveMeasure.hpp"
#include <iostream>	

void q_projectiveMeasure(float complex *state, int numqubits, std::vector<int> qubits_to_measure){

	RandomNumberGenerator* randomGen = new RandomNumberGenerator();

	std::map<int,float> mapping;
	std::pair<std::map<int,float>::iterator,bool> aux;

	int iterations = pow(2, numqubits);
	int mask = 0;

	float * tmp = new float[iterations];
	float acumulador = 0;

	for(unsigned int i = 0; i < qubits_to_measure.size(); i++)
		mask = mask | 1 << (numqubits - qubits_to_measure[i] - 1);




#pragma omp parallel for num_threads(4) 
	for (int i = 0 ; i < iterations ; i++){
		tmp[i] = pow(crealf(state[i]), 2) + pow(cimagf(state[i]), 2);
	}

	for (int i = 0 ; i < iterations ; i++){
		mapping[mask & i] += tmp[i];


		for (std::map<int, float>::iterator it=mapping.begin(); it!=mapping.end(); ++it){

			if(mask == it->first){

				tmp[i] = tmp[i]/it->second;
				
				std::cout << "index: " << tmp[i] << std::endl; // indice
			}
			else{
				tmp[i] = 0;
			}

		}

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
//			std::cout << "index: " << it->first << std::endl; // indice
//			std::cout << "measure result: " << it->second << std::endl; // measure
			break;
		}

	 }





	 delete(tmp);
	// std::cout << "Generated_Value: " << generatedValue << std::endl; // valor gerado no random

}
