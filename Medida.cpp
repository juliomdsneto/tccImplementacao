#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <complex.h>
#include <map>
#include <math.h>
using namespace std;
//setar cada posicao do vetor em: 1/sqrt(30), 2/sqrt(30), 3/sqrt(30), 4/sqrt(30) --check
// extrair o bit de um inteiro-----------deslocar o valor "00001" para se encontrar com o i
// med(numero de qubits, estado, qubit a ser medido, flag)

map<int,int> create_map(int numqubits, int valores_dos_qubits[]){
  map<int,int> m;
  
  uint mascara = pow(2,numqubits);
  
  uint nome_do_qubit = 0;


  while (--mascara > 0){
    m[nome_do_qubit] = valores_dos_qubits[nome_do_qubit];
    nome_do_qubit++;
  }

  return m;
}


void med(int numqubits, float complex *estado, char qubit_a_ser_medido, int flag){
    float complex m0, m1;
    m0=m1=0; 
    //*pow(2,numqubits-1)

      for(unsigned int i=pow(2,numqubits+1); i>0; i=i>>1){
        if(qubit_a_ser_medido & i){
          cout << "1"; 
        }
        else{
          cout << "0";
        }
    }
}


int main(){
    int numqubits = 2;
    float chance_de_ocorrencia = 1/sqrt(30);
    int* valores_dos_qubits = new int[1, 2, 3, 4];
    int iteracoes = pow(2, numqubits);
    char qubit_a_ser_medido = 2;
    int flag = 0;

    map<int,int> qubits = create_map(numqubits, valores_dos_qubits);
    float complex *estado= new float complex[iteracoes];

    for(int i = 0 ; i < iteracoes ; i++) {
      estado[i] = qubits[i] / chance_de_ocorrencia;
    }
//    estado[0]=1/sqrt(30); // qubit 00
//    estado[1]=2/sqrt(30);
//    estado[2]=3/sqrt(30);
//    estado[3]=4/sqrt(30);
//  estado[0]=sqrt(2)/2;
//    estado[1]=sqrt(2)/2;
    med(numqubits, estado, qubit_a_ser_medido, flag);
    printf("\n");
    return 0;
}