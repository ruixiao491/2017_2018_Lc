#! /bin/csh -f
foreach macro ($1)
foreach infile ($2)
foreach number ($3)
root -b<<EOF
.x $macro+("$infile", $number)
.q
#EOF
