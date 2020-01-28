#! /bin/csh -f
foreach macro ($1)
foreach infile ($2)
foreach outfile ($3)
root -b<<EOF
.x $macro+("$infile", "$outfile")
.q
#EOF
