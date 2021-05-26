N = int(input())
K = int(input())
ans = 1
dir_x, dir_y = [1, 0, -1, 0], [0, 1, 0, -1] # 우, 하, 좌, 상
board = [['O']*(N) for _ in range(N)]
tail = [(0,0)]
board[0][0] = 'S'
time = []
dir = []

for _ in range(K):
    y, x = map(int, input().split())
    board[y-1][x-1] = 'A'

K = int(input())

for _ in range(K):
    s, d = input().split()
    time.append(int(s))
    dir.append(d)

cur_x, cur_y = 0, 0
i = 0
while 0<=cur_x+dir_x[i]<N and 0<=cur_y+dir_y[i]<N: # 벽에 부딪히지 않는 동안
    
    nxt_y, nxt_x = cur_y+dir_y[i], cur_x+dir_x[i]
    #print("현재 시간 : ",ans ,"x위치 : ", nxt_x, "y 위치 : ", nxt_y)
    if board[nxt_y][nxt_x] == 'A': # 사과가 있을 경우
        board[nxt_y][nxt_x] = 'S'
        tail.append((nxt_y,nxt_x))  # 추후 꼬리에 추가
    elif board[nxt_y][nxt_x] == 'S':  # 뱀의 몸통과 부딪혔을 경우
        break
    else:  # 사과가 없을 경우
        cur_tail = tail[0]
        board[nxt_y][nxt_x] = 'S'
        board[cur_tail[0]][cur_tail[1]] = 'O'
        tail.append((nxt_y,nxt_x))
        del tail[0]
        
    if ans in time:
        idx = time.index(ans)
        if dir[idx] == 'L':  # 왼쪽으로 회전 후 이동
            if i-1<0:  # 기존 i가 0이었을 경우
                i = 3
            else:
                i = i-1
        else:
            i = (i+1)%4
    cur_x, cur_y = nxt_x, nxt_y
    ans+=1
print(ans)