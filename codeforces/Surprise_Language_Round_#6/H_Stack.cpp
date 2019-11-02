co plus
{
    dec [0]
    set [6] [[0]]
    dec [0]
    add [6] [6] [[0]]
    set [[0]] [6]
    inc [0]
    set [2] 42
    ac
}
 
co fois
{
    dec [0]
    set [6] [[0]]
    dec [0]
    mul [6] [6] [[0]]
    set [[0]] [6]
    inc [0]
    set [2] 42
    ac
} 
 
co number
{
    sub [1] [1] 48
    set [[0]] [1]
    set [2] 42
    inc [0]
    ac
}
 
co boucle
{
    cin [1]
    set [2] 0
    eq [4] [1] 43
    if [4] ca plus
    eq [4] [1] 42
    if [4] ca fois
    gt [4] [1] 47
    lt [5] [1] 58
    and [4] [5] [4]
    if [4] ca number
    eq [4] [2] 0
    if [4] ac
}
 
 
 
set [0] 10
ca boucle
dec [0]
iout [[0]]
ac
 
 