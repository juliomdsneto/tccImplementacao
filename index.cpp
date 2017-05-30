#include <iostream>
#include <complex.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include "./lib/QuantummProjectiveMeasure.hpp"

//void measure(float complex* state, int numqubits, vector<int>qubits_to_measure){
//passar vector com lista de qubit --> qubit a ser medido
  //a partir dessa lista, gerar a mascara(fazer depois)
//   gerar mascara;   (depois)
  //for (percorrer estado);
  //----usar a mascara na posição;  (manuamente por agora)
  //----acumular no map o quadrado de casa posição;
  //printar chaves do map--inteiro

int main() {

	std::map<int,float complex> test;
	std::pair<std::map<int,float complex>::iterator,bool> aux;


	int numqubits = 3;
	int iteracoes = pow(2, numqubits);
	int mask = 5; // provisorio
	int key_value;
	int aux1;

	std::vector<int> qubits_to_measure;

	float complex *state = new float complex[iteracoes];
	
	state[0] = 0.07142;
	state[1] = 0.14285;
	state[2] = 0.21428;
	state[3] = 0.28571;
	state[4] = 0.35714;
	state[5] = 0.42857;
	state[6] = 0.5;
	state[7] = 0.57142;


	for(int i = 0 ; i < iteracoes ; i++){//percorrer o estado
		

		test[mask & i] += cpowf(state[i], 2);

	}

	for (std::map<int, float complex>::iterator it=test.begin(); it!=test.end(); ++it)
	
    //std::cout << it->first << " => " << crealf(it->second) << '\n';
	std::srand(std::time(0));
	std::srand(1);
//	std::cout << rand()%100 << std::endl;

 	
	q_ProjectiveMeasureResolve(state, numqubits, qubits_to_measure);

}