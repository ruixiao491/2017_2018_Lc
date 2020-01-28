#!/bin/bash

INPUTFILE="/data/jisun/PbPb2015/HF2and_skim_MB1to7_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016.root"
OUTPUTFILE="/data/wangj/Data2015/Dntuple/PbPb/HF2and_skim_MB1to7_highpuritytk_D0_tkpt0p7eta1p5_goldenjson_02222016_1p.root"

root -l -b -q 'skimFiles.C+('\"$INPUTFILE\"','\"$OUTPUTFILE\"')'