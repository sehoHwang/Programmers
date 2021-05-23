import sys
sys.setrecursionlimit(10 ** 6)
"""
def dfs(y, x, N, M):
    board[y][x] = 0
    dir_x, dir_y = [0,0,1,-1], [1,-1,0,0]
    for i in range(4):
        nxt_y, nxt_x = y+dir_y[i], x+dir_x[i]
        if 0<=nxt_x and nxt_x<M and 0<=nxt_y and nxt_y<N and board[nxt_y][nxt_x] == 1:
            dfs(nxt_y, nxt_x, N, M)
        
T = int(input())
for _ in range(T):
    answer = 0
    M, N, K = map(int, input().split()) # M : 가로, N : 세로
    board = [[0]*M for _ in range(N)]
    
    for _ in range(K):
        x, y = map(int, input().split())
        board[y][x] = 1
    
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                dfs(i,j, N, M)
                answer+=1
    print(answer)
"""
def dfs(y, x, N, M):
    board[y][x] = 0
    dir_x, dir_y = [0,0,1,-1], [1,-1,0,0]
    for i in range(4):
        nxt_y, nxt_x = y+dir_y[i], x+dir_x[i]
        if 0<=nxt_x and nxt_x<M and 0<=nxt_y and nxt_y<N and board[nxt_y][nxt_x] == 1:
            dfs(nxt_y, nxt_x, N, M)
        
T = int(input())
for _ in range(T):
    answer = 0
    M, N, K = map(int, input().split()) # M : 가로, N : 세로
    board = [[0]*M for _ in range(N)]
    
    for _ in range(K):
        x, y = map(int, input().split())
        board[y][x] = 1
    
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                dfs(i,j, N, M)
                answer+=1
    print(answer)