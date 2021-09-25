#! /bin/csh -f
foreach macro ($1)
foreach branch ($2)
foreach outfile ($3)
foreach figuredir ($4)
root -b<<EOF
.x $macro("$branch","$outfile","$figuredir")
.q
#EOF
