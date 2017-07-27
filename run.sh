#!/bin/bash
GSL_RNG_SEED=$(date +%s%N) GSL_RNG_TYPE=mrg
./main_seq_sem_flags > saida_sequencial_semflags.txt
#./main_seq_O2 > saida_sequencial_O2.txt
#./main_seq_O1 > saida_sequencial_O1.txt
#./main_4t > saida4T.txt;
#./main_2t > saida2T.txt;
#./main_1t > saida1.Ttxt;



