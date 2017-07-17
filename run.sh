#!/bin/bash
GSL_RNG_SEED=$(date +%s%N) GSL_RNG_TYPE=mrg
#./main_2
#./main4 > saida4.txt;
#./main2 > saida2.txt;
#./main1 > saida1.txt;
./main_seq > saida_sequencial.txt;


