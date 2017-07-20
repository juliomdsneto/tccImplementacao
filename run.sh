#!/bin/bash
GSL_RNG_SEED=$(date +%s%N) GSL_RNG_TYPE=mrg
./main_seq > saida_seq.txt
#./main_4t > saida4T.txt;
#./main_2t > saida2T.txt;
#./main_1t > saida1.Ttxt;



