#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <complex.h>
#include <omp.h>
#include "../lib/RandomNumberGenerator.hpp"
#include "../lib/q_projetiveMeasure.hpp"

int main(int argc, char* argv[]) {

	int numqubits = 3;
	int iterations = pow(2, numqubits);
	
	std::vector<int> qubits_to_measure;

	qubits_to_measure.push_back(1);
	qubits_to_measure.push_back(2);
	qubits_to_measure.push_back(0);

	float *state = new float[iterations];
	state[0] = 0.071428571;
	state[1] = 0.142857143;
	state[2] = 0.214285714;
	state[3] = 0.285714286;
	state[4] = 0.357142857;
	state[5] = 0.428571429;
	state[6] = 0.5;

	q_projetiveMeasure(state, numqubits, qubits_to_measure);
}
