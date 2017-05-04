#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <complex.h>
#include <map>
#include <math.h>
#include <bitset>  
using namespace std;
//setar cada posicao do vetor em: 1/sqrt(30), 2/sqrt(30), 3/sqrt(30), 4/sqrt(30) --check
// extrair o bit de um inteiro-----------deslocar o valor "00001" para se encontrar com o i
// med(numero de qubits, estado, qubit a ser medido, flag)

map<int,int> create_map(){
  map<int,int> m;
  m[000000] = 0;
  m[000001] = 1;
  m[000100] = 4;
  m[000101] = 5;
  return m;
}
map<int,int> m = create_map();

string get_bits(unsigned int n){
		string ret;
		for (unsigned int mask=0x80000000; mask; mask>>=1) {
	    	ret += (n & mask) ? "1" : "0";
		}
		return ret;
	}

void med(int numqubits, float complex *estado, int n, int flag){
	float complex m0, m1;
	m0=m1=0;
	int x=1;
	get_bits(n);
	for(int i=0;i< pow(2,numqubits);i++){
		if (x & n){
			printf("%d\n",x);	
		}
		else{
			x= n >> 1;		
		}
	}

}

int main(){

	float complex *estado= new float complex [4];

	estado[0]=1/sqrt(30);
	estado[1]=2/sqrt(30);
	estado[2]=3/sqrt(30);
	estado[3]=4/sqrt(30);


	med(2, estado, 0, 0);

	printf("\n");



	return 0;
}