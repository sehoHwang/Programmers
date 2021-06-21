def dfs(num, len):
    if len == M:
        result.append(num)
        return

    for j in range(1, N+1):
        if visit[j]==False:
            visit[j] = True
            dfs(num+' '+str(j), len+1)
            visit[j] = False

N, M = map(int, input().split())
result = []
visit = [False]* (N+1)

for i in range(1,N+1):
    visit[i] = True
    dfs(str(i), 1)
    visit[i] = False

for r in result:
    print(r)