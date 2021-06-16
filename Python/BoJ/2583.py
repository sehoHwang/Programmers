from collections import deque

def tiling(x1, y1, x2, y2):
    #print(x1, y1, x2,y2)
    for i in range(y2, y1+1):
        for j in range(x1, x2+1):
            board[i][j] = 1

def bfs(y, x):
    cnt = 0
    q = deque()
    q.append([y,x])
    while q:
        cur_y, cur_x = q.popleft()
        #print("현재 좌표  :", cur_y, cur_x)
        cnt+=1
        #print(cur_y, cur_x, cnt)
        for i in range(4):
            new_y, new_x = cur_y+dy[i], cur_x+dx[i]
            if 0<=new_y<M and 0<=new_x<N and board[new_y][new_x]==0:
                q.append([new_y, new_x])
                board[new_y][new_x] = -1
                #print("삽입 좌표, 상태 : ", new_y, new_x, board[new_y][new_x])
    return cnt


dy = [-1, 1, 0, 0] # 상, 하, 좌, 우
dx = [0, 0, -1, 1]
M, N, K = map(int, input().split())
board = [[0]*N for _ in range(M)]
req_cnt = 0
count = []

for _ in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    x2 = x2-1
    y2 = y2-1
    y1 = M-1-y1
    y2 = M-1-y2

    tiling(x1, y1, x2, y2)
#print(board)

for i in range(M):
    for j in range(N):
        if board[i][j] == 0:
            board[i][j] = -1
            count.append(bfs(i,j))
            req_cnt +=1
            #print(">>> " , board)
count.sort()
print(req_cnt)
for c in count:
    print(c, end=' ')