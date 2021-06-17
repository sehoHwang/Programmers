def dfs(y, x, d):
    global cnt
    if board[y][x] == 0:
        cnt+=1
        board[y][x] = 2

    for _ in range(4):
        nxt_d = (d+3)%4
        nxt_y, nxt_x = y+dy[nxt_d], x+dx[nxt_d]
        if board[nxt_y][nxt_x] == 0:
            dfs(nxt_y, nxt_x, nxt_d)
            return
        d = nxt_d
    nxt_d = (d+2)%4
    nxt_y = y+dy[nxt_d]
    nxt_x = x+dx[nxt_d]
    if board[nxt_y][nxt_x] == 1:
        return
    
    dfs(nxt_y, nxt_x, d)
    


N, M = map(int, input().split())
cnt = 0
dx = [0, 1, 0, -1] # 북, 동, 남, 서
dy = [-1, 0, 1, 0]

cur_y, cur_x, d = map(int, input().split())
board = []

for _ in range(N):
    board.append(list(map(int, input().split())))

dfs(cur_y, cur_x, d)
print(cnt)


    