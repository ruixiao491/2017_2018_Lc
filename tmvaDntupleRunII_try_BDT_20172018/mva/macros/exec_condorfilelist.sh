#!/bin/sh

echo `hostname`
echo `date`
export SCRAM_ARCH=slc6_amd64_gcc491
source /cvmfs/cms.cern.ch/cmsset_default.sh
#export X509_USER_PROXY=/home/sun229/.myproxy
export X509_USER_PROXY=/home/xiao147/myproxy
DIR="tmvaDntupleRunII_try_BDT_20172018/mva/macros"
## I change the following line to the one that follows this line.
#cd /home/sun229/DmesonAna/Run2015Ana/CMSSW_7_5_8_patch2/src 
cd /home/xiao147/private/TMVA_lambdaC/CMSSW_10_3_3_patch1/src
eval `scramv1 runtime -sh`
cd $DIR

INFILELIST=$1
isPbPb=$2
STARTFILE=$3
ENDFILE=$4
OUTPUTDIR=$5

echo "INFILELIST: $INFILELIST"
echo "STARTFILE: $STARTFILE, ENDFILE: $ENDFILE"

if [ ! -d $OUTPUTDIR ]; then
	mkdir $OUTPUTDIR
fi

fileCounter=-1

while read line
do
	fileCounter=$((fileCounter+1))
	if [ $fileCounter -lt $STARTFILE ] || [ $fileCounter -ge $ENDFILE ]; then
		continue
	fi
	echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
	echo "<<<<<<<<<<<<< NEW INPUTFILE >>>>>>>>>>>>>>>>>"
	echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
	echo "fileCounter: $fileCounter, inputfile: $line"

	Inputfile=$line
	Outputfile="$OUTPUTDIR/Dntuple_$(basename ${Inputfile})_${fileCounter}.root"
	echo "Outputfile: $Outputfile"
        #./BDT_foreach_file.exe $Inputfile $Outputfile
        ./BDT_foreach_file_PbPb.exe $Inputfile $Outputfile
		#./../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin.exe $Inputfile $Outputfile
		#./../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_3_4.exe $Inputfile $Outputfile
		#./../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_rectangular_cuts.exe $Inputfile $Outputfile


	echo "<<<<<<<<<<<<< DONE!!!!!!! <<<<<<<<<<<<<<<<<"
done<$INFILELIST
echo `date`
