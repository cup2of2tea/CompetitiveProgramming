n=int(input())
one = 0
two = 0
liste = map(int,raw_input().split())
for money in liste:
    if(money == 25):
        one += 1
    elif(money == 50):
        if(one >= 1):
            one -= 1
        else:
            print('NO')
            exit(0)
        two += 1
    elif(two >=1 and one >= 1):
        two -= 1
        one -= 1
    elif(one >= 3):
        one -= 3
    else:
        print('NO')
        exit(0)
print('YES')