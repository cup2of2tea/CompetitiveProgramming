n = int(raw_input())
x = 0
while (n > 0):
    s = raw_input()
    if(s[1] == '-'):
        x = x - 1
    else:
        x = x + 1
    n = n - 1
print x