#include <iostream>
#include <complex.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdint.h>
#include "./lib/QuantummProjectiveMeasure.hpp"

//void measure(float complex* state, int numqubits, vector<int>qubits_to_measure){
//passar vector com lista de qubit --> qubit a ser medido
  //a partir dessa lista, gerar a mascara(fazer depois)
//   gerar mascara;   (depois)
  //for (percorrer estado);
  //----usar a mascara na posição;  (manuamente por agora) (check)
  //----acumular no map o quadrado de casa posição;   (check)
  //printar chaves do map--inteiro  (check)
//aplicar função de distribuicao uniforme na saida obtida, levando em consideracao a probabilidade de cada ocorrencia

// enum{
//    // Assumes W = 32 (omitting this)
//    N = 624,
//    M = 397,
//    R = 31,
//    A = 0x9908B0DF,    F = 1812433253,    U = 11,
//    // Assumes D = 0xFFFFFFFF (omitting this)    
//    S = 7,
//    B = 0x9D2C5680,    T = 15,
//    C = 0xEFC60000,    L = 18,    MASK_LOWER = (1ull << R) - 1,
//    MASK_UPPER = (1ull << R)

// };static uint32_t  mt[N];

// static uint16_t  index;// Re-init with a given seed

// void Initialize(const uint32_t  seed){
   
//    uint32_t  i;    
   
//    mt[0] = seed;    
   
//    for ( i = 1; i < N; i++ ){

//        mt[i] = (F * (mt[i - 1] ^ (mt[i - 1] >> 30)) + i);

//    }
   
//    index = N;
// }

// static void Twist(){
   
//    uint32_t  i, x, xA;    
   
//    for ( i = 0; i < N; i++ ){

//        x = (mt[i] & MASK_UPPER) + (mt[(i + 1) % N] & MASK_LOWER);        
//        xA = x >> 1;        
       
//        if ( x & 0x1 )
// 			xA ^= A;        
// 			mt[i] = mt[(i + M) % N] ^ xA;
//    }    
//    index = 0;
// }// Obtain a 32-bit random number

// uint32_t ExtractU32(){

//    uint32_t  y;
//    int i = index;    
//    if ( index >= N ){

//        Twist();
//        i = index;
//    }
// 	y = mt[i];
//    index = i + 1;    
//    y ^= (mt[i] >> U);
//    y ^= (y << S) & B;
//    y ^= (y << T) & C;
//    y ^= (y >> L);    
//    return y;
// }



int main() {

	std::map<int,float> test;
	std::pair<std::map<int,float>::iterator,bool> aux;

	int numqubits = 3;
	int iterations = pow(2, numqubits);
	int mask = 0; // provisorio
	
	float Generated_Value = 0;
	float acumulador = 0;
	
	std::vector<int> qubits_to_measure;

	qubits_to_measure.push_back(1);

	qubits_to_measure.push_back(2); //110

	for(int i = 0; i < qubits_to_measure.size(); i++){

		mask = mask | 1 << (numqubits - qubits_to_measure[i] - 1)  ;
	}

	std:: cout << mask << std::endl;

	float complex *state = new float complex[iterations];
	state[0] = 0.071428571;
	state[1] = 0.142857143;
	state[2] = 0.214285714;
	state[3] = 0.285714286;
	state[4] = 0.357142857;
	state[5] = 0.428571429;
	state[6] = 0.5;
	state[7] = 0.571428571;

	// state[0] = 0.182574186;
	// state[1] = 0.365148372;
	// state[2] = 0.547722558;
	// state[3] = 0.730296743;

	for(int i = 0 ; i < iterations ; i++){//percorrer o estado
		

		test[mask & i] += pow(crealf(state[i]), 2) + pow(cimagf(state[i]), 2);

	}


	for (std::map<int, float>::iterator it=test.begin(); it!=test.end(); ++it){
	
    std::cout << it->first << " => " << it->second << '\n';


	}


	std::srand(std::time(0));
	
	Generated_Value = rand() % 1000 +1;

	for(std::map<int, float>::iterator it=test.begin(); it!=test.end(); ++it) {

		acumulador += it->second * 1000;

		if(Generated_Value < acumulador)  {

			std::cout << "index: " << it->first << std::endl; // indice
			std::cout << "measure result: " << it->second << std::endl; // measure
			break;
		}

	}

	std::cout << "Generated_Value: " << Generated_Value << std::endl; // valor geradono random

	//std::cout << test.size() << std::endl;

 	
	//q_ProjectiveMeasureResolve(state, numqubits, qubits_to_measure);

}