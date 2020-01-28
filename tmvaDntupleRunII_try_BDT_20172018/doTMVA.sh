#!/bin/bash

DOTMVA=0
DOREADXML=1

PTBIN=(2 3 4 5 6 8 10 12.5 15 20)
RAA=(0.60 0.43 0.36 0.27 0.26 0.27 0.32 0.30 0.38)

COLSYST=('PbPb')
NSKIM=(197)
LUMI=(1.6419125)
#LUMI=(0.834692)

MVA=('CutsSA')

nPT=$((${#PTBIN[@]}-1))
nMVA=${#MVA[@]}
nCOL=${#COLSYST[@]}


# TMVAClassification.C #
if [ $DOTMVA -eq 1 ]; then
    j=0
    while ((j<$nCOL))
    do
        i=0
        while ((i<$nPT))
        do
	    cd myTMVA/
	    echo "-- Processing pT bin: ${PTBIN[i]} - ${PTBIN[i+1]} GeV/c"
	    echo
	    root -l -b -q 'TMVAClassification.C+('\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}')'
            
	    k=0
	    while ((k<$nMVA))
	    do
	        mv weights/TMVAClassification_${MVA[k]}.weights.xml weights/TMVA_${MVA[k]}_${COLSYST[j]}_${PTBIN[i]}_${PTBIN[i+1]}.weights.xml
	        mv weights/TMVAClassification_${MVA[k]}.class.C weights/TMVA_${MVA[k]}_${COLSYST[j]}_${PTBIN[i]}_${PTBIN[i+1]}.class.C
	        k=$(($k+1))
	    done
	    cd ..
	    i=$(($i+1))    
        done
        j=$(($j+1))
    done    
fi

# readxml.cc #
if [ $DOREADXML -eq 1 ]; then
    j=0
    while ((j<$nCOL))
    do
        i=0
        while ((i<$nPT))
        do
            k=0
            while ((k<$nMVA))
            do
                cd readxml/
                echo "-- Processing pT bin: ${PTBIN[i]} - ${PTBIN[i+1]} GeV/c"
                echo
                root -l -b -q 'readxml.cc+('\"../myTMVA/weights/TMVA_${MVA[k]}_${COLSYST[j]}_${PTBIN[i]}_${PTBIN[i+1]}.weights.xml\"','\"${MVA[k]}\"','\"${COLSYST[j]}\"','${PTBIN[i]}','${PTBIN[i+1]}','${LUMI[j]}','${RAA[i]}','${NSKIM[j]}')'
                k=$(($k+1))
                cd ..
            done
            i=$(($i+1))
        done
        j=$(($j+1))
    done
fi