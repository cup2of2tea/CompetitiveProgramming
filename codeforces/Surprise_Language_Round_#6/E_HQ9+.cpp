co boucle
{
   cin [0]
   gt [4] [0] 126
   if [4] ac
   lt [4] [0] 33
   if [4] ac
   eq [4] [0] 72
   if [4] 
       set [1] 1
   eq [4] [0] 81
   if [4] 
       set [1] 1
   eq [4] [0] 57
   if [4] 
       set [1] 1
   eq [4] [1] 1
   if [4]
       ac
}
 
co YES
{
    cout 89
    cout 69
    cout 83
    ac
}
 
co NO
{
    cout 78
    cout 79
    ac
}
    
 
 
set [1] 0
ca boucle
eq [4] [1] 1
if [4]
    ca YES
neq [4] [1] 1
if [4]
    ca NO
ac