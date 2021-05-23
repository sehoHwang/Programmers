N = int(input())
friends = []
answer = 0
for n in range(N):
    col = input()
    tmp = []
    for c in col:
        tmp.append(c)
    friends.append(tmp)
visit = [[0]*N for _ in range(N)]
#print(visit)
for i in range(N):
    for j in range(N):
        for z in range(N):
            if j==z:
                continue
            if friends[j][i] == 'Y' and friends[i][z] == 'Y' or (friends[j][z]== 'Y'):
                visit[j][z] = 1
                visit[z][j] = 1

for i in range(N):
    for j in range(N):
        if i==j:
            visit[i][j] = 0

for v in visit:
    cnt = 0
    for check in v:
        if check == 1:
            cnt+=1
    answer = max(answer, cnt)

print(answer)