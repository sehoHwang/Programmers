from collections import deque
def fish_pos(y, x): # 최소 거리에 있는 물고기 좌표 반환 -> 없을 경우 (-1,-1) 반환 
    min_dis = N*N
    min_y, min_x = -1, -1
    for i in range(N):
        for j in range(N):
            if board[i][j] != 0 and board[i][j]<size:
                if get_dis(y,x,i,j) == 0:
                    return min_y, min_x, min_dis
                cur_dis = get_dis(y,x,i,j)
                if min_dis != cur_dis:
                    min_dis = min(min_dis, cur_dis)
                    if min_dis == cur_dis:
                        min_y, min_x = i, j
            
    return min_y, min_x, min_dis

def get_dis(c_y, c_x, dst_y, dst_x): # 이동 거리를 반환하는 함수
    q = deque()
    q.append([c_y, c_x, 0])
    visit = [[False]*N for _ in range(N)]
    visit[c_y][c_x] = True
    
    while q:
        y, x, dis = q.popleft()
        if y==dst_y and x == dst_x:
            return dis
        for i in range(4):
            nxt_y, nxt_x = y+dy[i], x+dx[i]
            if 0<=nxt_y<N and 0<=nxt_x<N and visit[nxt_y][nxt_x] == False and board[nxt_y][nxt_x]<=size:
                q.append([nxt_y, nxt_x, dis+1])
                visit[nxt_y][nxt_x] = True
    return 0

N = int(input())
board = []
size = 2
answer = 0
dy = [-1, 1, 0, 0] # 상 하 좌 우
dx = [0, 0, -1, 1]
cur_y, cur_x = 0, 0
for _ in range(N):
    board.append(list(map(int, input().split())))

for i in range(N):
    for j in range(N):
        if board[i][j] == 9:
            cur_y, cur_x = i, j
board[cur_y][cur_x] = 0

cur_eat = 0     
while True:
    m_y, m_x, m_d = fish_pos(cur_y, cur_x)
    if m_y == -1 and m_x == -1:
        break
    
    cur_eat+=1
    if cur_eat == size:
        size+=1
        cur_eat = 0

    board[m_y][m_x] = 0 # 물고기가 잡힘
    answer += m_d
    cur_y, cur_x = m_y, m_x

print(answer)
