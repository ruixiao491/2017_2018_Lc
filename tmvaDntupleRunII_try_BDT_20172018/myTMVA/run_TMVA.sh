#! /bin/csh -f
foreach macro ($1)
foreach collision ($2)
foreach pTmin ($3)
foreach pTmax ($4)
foreach method ($5)
foreach number ($6)
foreach varialbe_list ($7)
foreach name_variable ($8)
root -b<<EOF
.x $macro+("$collision",$pTmin,$pTmax,"$method",$number,"$varialbe_list","$name_variable")
.q
#EOF
