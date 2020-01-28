#!/bin/bash

DOVARIABLES=1

#PTBIN=(6 8)
PTBIN=(2 3 4 5 6 8 10 12.5 15 20)
COLSYST=('PbPb')
VAR=('(DsvpvDistance/DsvpvDisErr)' 'Dchi2cl')
VARNAME=('decaylength' 'vprob')
VARLATEX=('d_{0}/Err(d_{0})' 'vertexProbability')
VARN=(50 50)
VARMIN=(2.5 0)
VARMAX=(12.5 1)

nPT=$((${#PTBIN[@]}-1))
nCOL=${#COLSYST[@]}
nVAR=${#VAR[@]}

if [ $DOVARIABLES -eq 1 ]; then
    j=0
    while ((j<$nCOL))
    do
        i=0
        while ((i<$nPT))
        do
            k=0
            while ((k<$nVAR))
            do
                echo "-- Processing pT bin: ${PTBIN[i]} - ${PTBIN[i+1]} GeV/c"
                echo
                root -l -b -q 'variables.C+('\"${VAR[k]}\"','\"${VARNAME[k]}\"','\"${VARLATEX[k]}\"','${VARN[k]}','${VARMIN[k]}','${VARMAX[k]}','\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}')'
                k=$(($k+1))
            done
            i=$(($i+1))
        done
        j=$(($j+1))
    done
fi