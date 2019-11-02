def less_lucky(k,n):
    while(n != 0):
        if( n%10 == 7 or n%10 == 4):
            k-=1
        if(k < 0):
            return 0
        n=n//10
    return 1
N,K=map(int,raw_input().split())
l=map(int,raw_input().split())
res=0
for i in l:
    res+=less_lucky(K,i)
print(res)