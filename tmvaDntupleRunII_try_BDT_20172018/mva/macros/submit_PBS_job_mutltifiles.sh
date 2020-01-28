#!/bin/sh

if [ "$#" -ne 5 ]; then
	echo "Wrong number of parameters. 5 expected, passed $#"
	exit
fi

INFILELIST=$1
isPbPb=$2  # need to be set in loop.C
FilePerJob=$3
OUTPUTDIR=$4
JobIndex=$5
TotalFiles=$(wc -l < "$INFILELIST")
Njobs=$((TotalFiles/FilePerJob+1))

echo "INFILELIST: $INFILELIST"
echo "Total number of file: $TotalFiles, FilePerJob: $FilePerJob"
echo "$Njobs jobs will be submitted"

#rm ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin.exe
#g++ ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin.C $(root-config --cflags --libs) -Wall -O2 -o ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin.exe

#rm ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_3_4.exe
#g++ ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_3_4.C $(root-config --cflags --libs) -Wall -O2 -o ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_3_4.exe

#rm ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_rectangular_cuts.exe
#g++ ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_rectangular_cuts.C $(root-config --cflags --libs) -Wall -O2 -o ../../masstuples/make_tuple_for_Roofit_alldata_pp_agreedMC_noalpha_uniform_cutsgetfromKevin_rectangular_cuts.exe

##rm  BDT_foreach_file.exe
##g++ BDT_foreach_file.C $(root-config --cflags --libs) -Wall -O2 -o BDT_foreach_file.exe


##rm  BDT_foreach_file_PbPb.exe
##g++ BDT_foreach_file_PbPb.C $(root-config --cflags --libs) -Wall -O2 -o BDT_foreach_file_PbPb.exe

if [ ! -d $OUTPUTDIR ]; then
    mkdir $OUTPUTDIR
fi

for ((count=1; count <= $Njobs; count++))
do
	echo "Job $count"

	#decide start file and end file
	STARTFILE=$(((count-1)*FilePerJob))
	ENDFILE=$((count*FilePerJob))
	if [ $ENDFILE -gt $TotalFiles ]; then
		ENDFILE=$TotalFiles
	fi
	echo "Files from $STARTFILE to $ENDFILE"

# make the PBS file
cat > PBS_${STARTFILE}to${ENDFILE}_${JobIndex}.sh <<EOF
#!/bin/sh

#PBS -l nodes=1,walltime=04:00:00,mem=2400MB
#PBS -N Dntuple_${STARTFILE}to${ENDFILE}_${JobIndex}
#PBS -o /home/xiao147/private/TMVA_lambdaC/CMSSW_10_3_3_patch1/src/tmvaDntupleRunII_try_BDT_20172018/mva/macros/PBS_${STARTFILE}to${ENDFILE}_${JobIndex}.log
#PBS -e /home/xiao147/private/TMVA_lambdaC/CMSSW_10_3_3_patch1/src/tmvaDntupleRunII_try_BDT_20172018/mva/macros/PBS_${STARTFILE}to${ENDFILE}_${JobIndex}.err
#PBS -r n
#PBS -V
#PBS -q standby

cd /home/xiao147/private/TMVA_lambdaC/CMSSW_10_3_3_patch1/src/tmvaDntupleRunII_try_BDT_20172018/mva/macros

./exec_condorfilelist.sh $INFILELIST $isPbPb $STARTFILE $ENDFILE $OUTPUTDIR
EOF

	chmod 744 PBS_${STARTFILE}to${ENDFILE}_${JobIndex}.sh

	qsub PBS_${STARTFILE}to${ENDFILE}_${JobIndex}.sh
	echo "PBS_${STARTFILE}to${ENDFILE}_${JobIndex}.sh submitted"

done
