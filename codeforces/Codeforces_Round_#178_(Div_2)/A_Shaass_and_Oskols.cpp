n = int(raw_input())
a = map(int,raw_input().split())
m = int(raw_input())
for i in range(m):
    x,y = map(int,raw_input().split())
    x -= 1
    if(x+1 < n):
        a[x+1] += a[x] - y
    if(x-1 >= 0):
        a[x-1] += y-1
    a[x] = 0
for bird in a:
    print(bird)