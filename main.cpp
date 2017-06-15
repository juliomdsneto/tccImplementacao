#include <iostream>
#include <complex.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdint.h>
#include "./lib/QuantummProjectiveMeasure.hpp"
#include "./lib/RandomNumberGenerator.hpp"

//#==========#
int main(int argc, char* argv[]) 
{
	RandomNumberGenerator* randomGen = new RandomNumberGenerator();
	std::map<int,float> test;
	std::pair<std::map<int,float>::iterator,bool> aux;

	int numqubits = 3;
	int iterations = pow(2, numqubits);
	
	float Generated_Value = 0;
	float acumulador = 0;
	
	std::vector<int> qubits_to_measure;

	qubits_to_measure.push_back(1);
	qubits_to_measure.push_back(2);
	int mask =0;

	for(int i = 0; i < qubits_to_measure.size(); i++)
		mask = mask | 1 << (numqubits - qubits_to_measure[i] - 1)  ;

	std:: cout << mask << std::endl;

	float *state = new float[iterations];
	state[0] = 0.071428571;
	state[1] = 0.142857143;
	state[2] = 0.214285714;
	state[3] = 0.285714286;
	state[4] = 0.357142857;
	state[5] = 0.428571429;
	state[6] = 0.5;
	state[7] = 0.571428571;


	for (int i = 0 ; i < iterations ; i++)
		test[mask & i] += pow(crealf(state[i]), 2) + pow(cimagf(state[i]), 2);

	for (std::map<int, float>::iterator it=test.begin(); it!=test.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	
	unsigned long int generatedValue = randomGen->random();

	for(std::map<int, float>::iterator it=test.begin(); it!=test.end(); ++it) {
		acumulador += it->second * 1000;

		if(generatedValue < acumulador){
			std::cout << "index: " << it->first << std::endl; // indice
			std::cout << "measure result: " << it->second << std::endl; // measure
			break;
		}

	}
	std::cout << "Generated_Value: " << generatedValue << std::endl; // valor gerado no random
}
