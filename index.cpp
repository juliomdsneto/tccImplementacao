#include <iostream>
#include <complex.h>
#include <cmath>
#include <vector>
#include "./lib/QuantummProjectiveMeasure.hpp"
//0.182574186
//0.707106781

//void measure(float complex* state, int numqubits, vector<int>qubits_to_measure){
//passar vector com lista de qubit --> qubit a ser medido
  //a partir dessa lista, gerar a mascara(fazer depois)
//   gerar mascara;   (depois)
  //for (percorrer estado);
  //----usar a mascara na posição;  (manuamente por agora)
  //----acumular no map o quadrado de casa posição;
  //printar chaves do map--inteiro

int main() {
	int numqubits = 3;
	int iteracoes = pow(2, numqubits);

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
	q_ProjectiveMeasureResolve(state, numqubits, qubits_to_measure);

}