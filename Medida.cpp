#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <complex.h>
#include <map>
#include <math.h>
using namespace std;
//setar cada posicao do vetor em: 1/sqrt(30), 2/sqrt(30), 3/sqrt(30), 4/sqrt(30) --check
// extrair o bit de um inteiro-----------deslocar o valor "00001" para se encontrar com o i
// med(numero de qubits, estado, qubit a ser medido, flag)
// n pode medir apenas 1 qubit em um sistema com multiplos qubits

map<int,int> create_map(int numqubits, int valores_dos_qubits[]){
  map<int,int> m;
  
  unsigned int mascara = pow(2,numqubits) +1;
  
  unsigned int nome_do_qubit = 0;


  while (--mascara > 0){
    m[nome_do_qubit] = valores_dos_qubits[nome_do_qubit];
    nome_do_qubit++;
  }

  return m;
}
void med(int numqubits, float complex *estado, char qubit_a_ser_medido, int flag){
    float complex m0, m1;
    m0=m1=0;
    float chance_de_ocorrencia = 1/sqrt(30);
	int* valores_dos_qubits = new int[4];
	valores_dos_qubits[0] = 1;
	valores_dos_qubits[1] = 2;
	valores_dos_qubits[2] = 3;
	valores_dos_qubits[3] = 4;
	int iteracoes=pow(2,numqubits);
    map<int,int> qubits = create_map(numqubits, valores_dos_qubits);
   	float complex *valor_da_medida=new float complex[iteracoes];
    for(int i = 0 ; i < pow(2,numqubits); i++){
		estado[i] = qubits[i] * chance_de_ocorrencia; // 1 * (1/sqrt(30))
      	valor_da_medida[i]=estado[i]*estado[i]; // (1 * (1/sqrt(30)))^2
 
 // normalizacao    	valor_da_medida[i]=chance_de_ocorrencia / valor_da_medida[i]; // (1/sqrt(30)/((1 * (1/sqrt(30)))^2)  )

		printf("%f -- %+fi \n", creal(valor_da_medida[i]), cimag(valor_da_medida[i]));
    }
       
}


int main(){
    int numqubits = 2;
    int flag = 0;
    int iteracoes = pow(2, numqubits); 
    float complex *estado= new float complex[iteracoes];
    char qubit_a_ser_medido = 2;
//    estado[0]=1/sqrt(30); // qubit 00
//    estado[1]=2/sqrt(30);
//    estado[2]=3/sqrt(30);
//    estado[3]=4/sqrt(30);
//  estado[0]=sqrt(2)/2;
//    estado[1]=sqrt(2)/2;
    med(numqubits, estado, qubit_a_ser_medido, flag);
    cout << "\n";
    return 0;
}