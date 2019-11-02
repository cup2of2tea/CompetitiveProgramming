co boucle
{
     eq [4] [0] 0
     if [4]
         ac
     mod [3] [0] 2
     set [[5]] [3]
     inc [5]
     div [0] [0] 2
}
 
co afficher
{
    eq [4] [5] 6
    if [4] ac
    dec [5]
    iout [[5]]
}
 
iin [0]
set [5] 6
ca boucle
ca afficher
ac