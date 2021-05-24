from sys import stdin
from collections import deque

def movemove(x, y, dx, dy):
    move = 0
    while board[y+dy][x+dx] != '#':
        if board[y+dy][x+dx] == 'O':
            return 0, 0, 0
        y+=dy
        x+=dx
        move+=1
    return x, y, move

def bfs():
    visit = {}
    dir_x, dir_y = [0, 0, 1, -1], [1, -1, 0, 0]
    q = deque([red+blue])
    visit[red[0],red[1],blue[0],blue[1]] = 0
    while q :
        ry, rx, by, bx = q.popleft()
        for dx, dy in zip(dir_x, dir_y):
            
            nrx, nry, rmove = movemove(rx, ry, dx, dy)
            nbx, nby, bmove = movemove(bx, by, dx, dy)

            if nbx == 0 and nby==0 :
                continue
            elif nrx ==0 and nry ==0 :
                print(visit[ry,rx,by,bx] + 1)
                return
            elif nrx == nbx and nry == nby:
                if rmove<bmove:
                    nbx-=dx
                    nby-=dy
                else :
                    nrx-=dx
                    nry-=dy
            if (nry, nrx, nby, nbx) not in visit:
                visit[nry,nrx,nby,nbx] = visit[ry,rx,by,bx] + 1
                q.append([nry, nrx, nby, nbx])
        if not q or visit[ry,rx,by,bx] >= 10:
            print(-1)
            return

N, M = map(int, input().split()) # N : 세로, M : 가로
board = [list(stdin.readline()) for _ in range(N)]

for i in  range(N):
    for j in range(M):
        if board[i][j] == 'B':
            blue = [i,j]
            board[i][j] = '.'
        if board[i][j] == 'R':
            red = [i,j]
            board[i][j] = '.'
bfs()

