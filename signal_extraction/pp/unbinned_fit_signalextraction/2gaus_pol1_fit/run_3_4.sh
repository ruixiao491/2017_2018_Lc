#! /bin/csh -f
foreach macro ($1)
foreach values ($2)
foreach outfile ($3)
foreach figuredir ($4)
foreach numbers_val ($5)
root -b<<EOF
.x $macro+($values,"$outfile", "$figuredir",$numbers_val)
.q
#EOF
