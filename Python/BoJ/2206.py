import copy
from collections import deque

dy = [-1, 1, 0, 0] # 상 하 좌 우
dx = [0, 0, -1, 1]
inf = 10000000
def bfs(graph):
    
    q = deque()
    q.append((0,0,0))
    visit[0][0][0] = 1
    while q:
        x, y, z = q.popleft()

        for i in range(4):
            nxt_x, nxt_y = x+dx[i], y+dy[i]
            if 0<=nxt_x<N and 0<=nxt_y<M:
                if graph[nxt_x][nxt_y] == 0 and visit[nxt_x][nxt_y][z] == -1:
                    visit[nxt_x][nxt_y][z] = visit[x][y][z]+1
                    q.append((nxt_x, nxt_y, z))
                elif z == 0 and graph[nxt_x][nxt_y] == 1 and visit[nxt_x][nxt_y][1] == -1:
                    visit[nxt_x][nxt_y][1] = visit[x][y][z] + 1
                    q.append((nxt_x,nxt_y,1))


N, M = map(int, input().split())
min_dis = inf
graph = []

visit = [[[-1]*2 for _ in range(M)] for _ in range(N)]
for _ in range(N):
    graph.append(list(map(int,input())))

new_g = copy.deepcopy(graph)
bfs(new_g)
ans1, ans2 = visit[N-1][M-1][0], visit[N-1][M-1][1]

if ans1 == -1 and ans2!=-1:
    print(ans2)
elif ans1!=-1 and ans2==-1:
    print(ans1)
else :
    print(min(ans1,ans2))
