n = int(input())
m = int(input())
inf = 100000000
s = [[inf]*n for _ in range(n)]

for _ in range(m):
    i, j, w = map(int, input().split())
    if s[i-1][j-1] != 0:
        if s[i-1][j-1] > w:
            s[i-1][j-1] = w

for i in range(n):
    for j in range(n):
        for z in range(n):
            if j!=z and s[j][z] > s[j][i]+s[i][z]:
                s[j][z] = s[j][i]+s[i][z]

for i in s:
    for j in i:
        if j == inf:
            print(0, end=' ')
        else:
            print(j, end=' ')
    print()