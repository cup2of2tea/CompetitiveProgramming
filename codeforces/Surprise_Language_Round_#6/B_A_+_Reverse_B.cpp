co reverse
{
    cin [3]
    lt [4] [3] 48
    if [4] ac
    gt [4] [3] 57
    if [4] ac
    set [[2]] [3]
    inc [2]
}
 
co reverse2
{
    eq [4] [2] 6
    if [4] ac
    dec [2]
    mul [1] [1] 10
    add [1] [1] [[2]]
    sub [1] [1] 48
}
 
iin [0]
set [1] 0
set [2] 6
cin [3]
ca reverse
ca reverse2
add [0] [0] [1]
iout [0]
ac
 