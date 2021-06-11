from collections import deque

def dfs(s):
    visit[s] = 1
    for i in range(N):
        if nodes[s][i] == 1 and visit[i]==0:
            dfs(i)

N, M = map(int, input().split())
result = 0
q = deque()
nodes = [[0]*N for _ in range(N)]
visit = [0 for _ in range(N)]
for _ in range(M):
    x, y = map(int, input().split())
    nodes[x-1][y-1] = 1
    nodes[y-1][x-1] = 1

for i in range(N):
    if visit[i]==0:
        dfs(i)
        result+=1
            
print(result)