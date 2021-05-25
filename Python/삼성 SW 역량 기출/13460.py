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
    q = deque([red+blue])
    visit = {}
    dir_y, dir_x = [-1, 1, 0, 0], [0, 0, -1, 1] # 상 하 좌 우
    visit[red[0],red[1],blue[0],blue[1]] = 0  # r_y, r_x, b_y, b_x
    while q:
        ry, rx, by, bx = q.popleft()

        for i in range(4):
            new_rx, new_ry, rmove = movemove(rx, ry, dir_x[i], dir_y[i])
            new_bx, new_by, bmove = movemove(bx, by, dir_x[i], dir_y[i])
            
            if new_bx == 0 and new_by == 0 :  # 파라색 공이 구멍에 빠질 때
                continue
            elif new_rx == 0 and new_ry == 0:  # 빨간색 공만 구멍에 빠질 때
                print(visit[ry, rx, by, bx] + 1)
                return
            elif new_ry == new_by and new_rx == new_bx:
                if rmove<bmove:
                    new_bx-=dir_x[i]
                    new_by-=dir_y[i]
                else:
                    new_rx-=dir_x[i]
                    new_ry-=dir_y[i]
            
            if (new_ry, new_rx, new_by, new_bx) not in visit:
                visit[new_ry, new_rx, new_by, new_bx] = visit[ry, rx, by, bx] + 1
                q.append([new_ry, new_rx ,new_by ,new_bx])
            
        if not q or visit[ry,rx,by,bx] >= 10:
            print(-1)
            return

N, M = map(int, input().split())

board = [input() for _ in range(N)]

for i in range(N):
    for j in range(M):
        if board[i][j] == 'B':
            blue = [i,j]
        if board[i][j] == 'R':
            red = [i,j]

bfs()
    
    
    