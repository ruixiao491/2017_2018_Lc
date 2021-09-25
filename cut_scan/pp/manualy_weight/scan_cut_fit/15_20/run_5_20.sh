#! /bin/csh -f
foreach macro ($1)
foreach infile ($2)
foreach outfile ($3)
foreach figuredir ($4)
foreach range1 ($5)
foreach range2 ($6)
root -b<<EOF
.x $macro+("$infile", "$outfile", "$figuredir",$range1,$range2)
.q
#EOF



