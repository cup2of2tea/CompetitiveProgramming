co loop
{
    eq [1] [0] 0
    if [1] ac
    add [2] [2] [3]
    dec [0]
}
 
iin [0]
set [2] 0
set [3] [0]
ca loop
add [4] [2] [2]
sub [4] [4] [3]
iout [4]
ac
 