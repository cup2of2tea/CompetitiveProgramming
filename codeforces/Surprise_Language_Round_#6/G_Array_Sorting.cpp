co tableau
{
    add [3] [0] 10
    eq [2] [1] [3]
    if [2] ac
    iin [4]
    set [[1]] [4]
    inc [1]
}
 
co afficher
{
    eq [4] [1] 10
    if [4] ac
    dec [1]
    iout [[1]]
    cout 10
}
 
 
co swap
{
    set [7] [[4]]
    set [[4]] [[6]]
    set [[6]] [7]
    set [3] 1
    ac
}
 
co sort2
{
    add [5] [0] 9
    eq [6] [4] [5]
    if [6] ac
    add [6] [4] 1
    lt [5] [[4]] [[6]]
    if [5] ca swap
    inc [4]
}
    
 
co sort
{
    set [3] 0
    set [4] 10
    ca sort2
    eq [2] [3] 0
    if [2]
        ac
}
 
 
iin [0]
set [1] 10
ca tableau
ca sort
ca afficher
ac
 
 
 
 