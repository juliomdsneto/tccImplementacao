#!/bin/bash


for i in `seq 1 10`
do
GSL_RNG_SEED=$(date +%s%N) GSL_RNG_TYPE=mrg /usr/bin/time ./main &>>teste.txt
done



