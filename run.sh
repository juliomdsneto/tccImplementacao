#!/bin/bash
GSL_RNG_SEED=$(date +%s%N) GSL_RNG_TYPE=mrg
./main_4T > saida4T.txt;
./main_2T > saida2T.txt;
./main_1T > saida1T.txt;
./main_seq > saida_seq.txt;


