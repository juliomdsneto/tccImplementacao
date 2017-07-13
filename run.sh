#!/bin/bash
GSL_RNG_SEED=$(date +%s%N) GSL_RNG_TYPE=mrg
#./main_2
./main_seq > saida_seq.txt;
./main_1 > saida_par1.txt;
./main2 > saida_par2.txt;
./main_4 > saida_par4.txt;


