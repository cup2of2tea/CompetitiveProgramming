point = [25, 18, 15, 12, 10, 8, 6, 4, 2, 1]+[0]*50
 
t = input()
score = {}
 
for i in range(t):
    n = input()
    for j in range(n):
        name = raw_input()
        if name not in score:
            score[name] = [0]*51+[name]
        score[name][0] += point[j]
        score[name][j+1] += 1
 
s = score.values()
print sorted(s)[-1][-1]
 
s = [[x[1]]+x for x in s]
print sorted(s)[-1][-1]