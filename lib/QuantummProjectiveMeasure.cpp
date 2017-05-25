#include <string>
#include <iostream>
#include <cmath>
#include "QuantummProjectiveMeasure.hpp"



std::map<int,int> teste, teste1;
std::pair<std::map<int,int>::iterator, bool> aux;


void q_ProjectiveMeasureResolve (float complex *state, int numqubits, std::vector<int> qubits_to_measure) {
	
	int mask = 5; // valor quaquer
	int iteracoes = pow(numqubits, 2);
	int key_value;

	for(int i = 0 ; i < iteracoes; i++){//percorrer todo o estado, pra cada nova hash que for gerada, armazenar ela elevada ao quadrado

		key_value = mask & i;
	    aux = teste.insert(std::pair<int,int>(key_value, i));// chave do map, 

	}
}
