#!/bin/sh
###here to submit slurm
#a=$(squeue -u xiao147 | wc -l)
b=1

filename='test_summary_Dntuple.sh'
n=1
while read line; do
#read each line
echo $line
$line
a=$(squeue -u xiao147 | wc -l)
while [[ $a > $b ]]; do
	sleep 5m
	a=$(squeue -u xiao147 | wc -l)
	echo $a
done

done < $filename
