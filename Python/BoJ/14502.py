from itertools import product, combinations
from collections import deque
import copy # for deep copy

dy = [-1, 1, 0, 0] # 상 하 좌 우
dx = [0, 0, -1, 1]

def bfs(i, j):
    cnt = 0
    m[i][j] = -1
    q = deque()
    q.append([i,j])
    while q:
        y, x = q.popleft()
        cnt+=1
        for d in range(4):
            nxt_y = y+dy[d]
            nxt_x = x+dx[d]
            if 0<=nxt_y<N and 0<=nxt_x<M and m[nxt_y][nxt_x]!=-1 and m[nxt_y][nxt_x] ==0 and m[nxt_y][nxt_x]!=1:
                m[nxt_y][nxt_x] = -1
                q.append([nxt_y, nxt_x])
    return cnt

N, M = map(int, input().split())
answer = []
board = []
arr1 = [i for i in range(N)] # y 좌표의 모음
arr2 = [i for i in range(M)] # x 좌표의 모음
cnt_i = 0
tmp = list(product(arr1, arr2))
comb = list(combinations(tmp, 3))

for _ in range(N):
    row = list(map(int,input().split()))
    board.append(row)

for i in range(N):
    for j in range(M):
        if board[i][j] == 1:
            cnt_i+=1

for c in comb:
    result = 0
    w1, w2, w3 = c[0], c[1], c[2]

    if board[w1[0]][w1[1]] == 0 and board[w2[0]][w2[1]] == 0 and board[w3[0]][w3[1]] == 0: # 벽을 세개를 다 세울 수 있는 경우
        m = copy.deepcopy(board)
        m[w1[0]][w1[1]] = 1 # 벽을 세우는 과정
        m[w2[0]][w2[1]] = 1
        m[w3[0]][w3[1]] = 1
        for a in range(N):
            for b in range(M):
                if m[a][b] == 2 and m[a][b]!=-1:
                    result += bfs(a, b)
    if result != 0 and result not in answer:
        answer.append(result)
result = N*M - min(answer) - cnt_i - 3
print(result)