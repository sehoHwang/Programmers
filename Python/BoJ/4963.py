import sys
sys.setrecursionlimit(10000)

dy = [-1, 1, 0, 0, -1, 1, 1, -1]
dx = [0, 0, 1, -1, 1, 1, -1, -1]

def dfs(i, j):
    visit[i][j] = 1
    
    for r in range(8):
        nxt_y = i+dy[r]
        nxt_x = j+dx[r]
        if 0<=nxt_y<h and 0<=nxt_x<w and visit[nxt_y][nxt_x]==0 and board[nxt_y][nxt_x]==1:
            dfs(nxt_y, nxt_x)

answer = []
while True:

    w, h = map(int, input().split())
    result = 0
    if w == 0 and h == 0:
        break
    visit = [[0]*w for _ in range(h)]
    board = []
    
    for _ in range(h): # map 그리기
        row = list(map(int, input().split()))
        board.append(row)
    
    for i in range(h):
        for j in range(w):
            if visit[i][j] == 0 and board[i][j] == 1:
                dfs(i,j)
                result+=1

    answer.append(result)

for a in answer:
    print(a)