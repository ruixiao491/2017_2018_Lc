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


##rm  loop.exe
##g++ loop.C $(root-config --cflags --libs) -Wall -O2 -o loop.exe

#rm small_tree/check_event_number.exe
#g++ small_tree/check_event_number.C $(root-config --cflags --libs) -Wall -O2 -o small_tree/check_event_number.exe


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

# make the SBATCH file
cat > SBATCH_${STARTFILE}to${ENDFILE}_${JobIndex}.sh <<EOF
#!/bin/sh


#SBATCH -N 1
#SBATCH -t 04:00:00
#SBATCH --mem=2400MB
#SBATCH --job-name=Dntuple_${STARTFILE}to${ENDFILE}_${JobIndex}
#SBATCH -o /home/xiao147/private/TMVA_lambdaC/CMSSW_7_5_8_patch3/src/tmvaDntupleRunII_try_BDT_20172018/mva/macros/pp_refillBDTG/SBATCH_${STARTFILE}to${ENDFILE}_${JobIndex}.log
#SBATCH -e /home/xiao147/private/TMVA_lambdaC/CMSSW_7_5_8_patch3/src/tmvaDntupleRunII_try_BDT_20172018/mva/macros/pp_refillBDTG/SBATCH_${STARTFILE}to${ENDFILE}_${JobIndex}.err
#SBATCH --no-requeue
#SBATCH --export=ALL
#SBATCH -A standby


./exec_condorfilelist.sh $INFILELIST $isPbPb $STARTFILE $ENDFILE $OUTPUTDIR
EOF

	chmod 744 SBATCH_${STARTFILE}to${ENDFILE}_${JobIndex}.sh

	sbatch SBATCH_${STARTFILE}to${ENDFILE}_${JobIndex}.sh
	echo "SBATCH_${STARTFILE}to${ENDFILE}_${JobIndex}.sh submitted"

done
