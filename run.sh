#!/bin/bash
GSL_RNG_SEED=$(date +%s%N) GSL_RNG_TYPE=mrg
./main_seq_Ofast > saida_seq_Ofast.txt;
#./main_seq_O2 > saida_seq_O2.txt;
#./main_seq_O1 > saida_seq_O1.txt



