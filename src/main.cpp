#include <iostream>
#include <map>
#include <cmath>
#include <stdio.h>
#include <sys/time.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdint.h>
#include <complex.h>
#include <omp.h>
#include "../lib/RandomNumberGenerator.hpp"
#include "../lib/q_projectiveMeasure.hpp"


int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1){
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void print_statistic(std::vector <float> amostra){
	float med, desv;
	med = desv = 0;
	int number = amostra.size();

	sort(amostra.begin(), amostra.end());

	for (int i = 0; i < number; i++){
//		cout << amostra[i] << endl;
		med += amostra[i];
	}
	med /= (number);

	for (int i = 0; i < number; i++){
		desv += pow((amostra[i] - med),2.0);
	}

	desv = sqrt(desv/(number-1)) / med * 100.0;

	std::cout << med << "\t\tDESV %: " << desv << std::endl;

}


int main(int argc, char* argv[]) {

	int numqubits = 20;

	std::vector<int> qubits_to_measure;

	std::vector<float> amostra;

	qubits_to_measure.push_back(1);
	qubits_to_measure.push_back(2);
	qubits_to_measure.push_back(0);

//	float *state = new float[iterations];


	struct timeval timev, tvBegin, tvEnd;

	for(int i = 20; i<29; i++ ){//variando qubits de 20 ate 28

		int iterations = pow(2, i);// i	

		float complex *state = new float complex[iterations]();

		state[0] = 1;


	// state[0] = 0.071428571;
	// state[1] = 0.142857143;
	// state[2] = 0.214285714;
	// state[3] = 0.285714286;
	// state[4] = 0.357142857;
	// state[5] = 0.428571429;
	// state[6] = 0.5;
	// state[7] = 0.57142;


		std::cout << "QUBITS: " << i << std::endl;

		qubits_to_measure.clear();

		for(int j = 0; j < i; j++){//variando quantidade de qubits a serem lidos  
			qubits_to_measure.push_back(j);

			amostra.clear();

			std::cout << "QUBITS a serem lidos: " << qubits_to_measure.size() << std::endl;			

			for(int k = 0; k<30; k++){//numero de execucoes --- 30


				gettimeofday(&tvBegin, NULL);

				q_projectiveMeasure(state, numqubits, qubits_to_measure);

					
				gettimeofday(&tvEnd, NULL);
				timeval_subtract(&timev, &tvEnd, &tvBegin);
				float t = timev.tv_sec + (timev.tv_usec / 1000000.0);
				amostra.push_back(t);
			}

			print_statistic(amostra);

		}
		delete(state);

	}
	

}
