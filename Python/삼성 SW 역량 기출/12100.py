import sys, copy

def movemove(dir):
    if dir == 0: # 상
        for i in range(N):
            top = 0
            for j in range(1, N):
                if board[j][i]:
                    temp = board[j][i]
                    board[j][i] = 0
                    if board[top][i] == 0:
                        board[top][i] = temp
                    elif board[top][i] == temp:
                        board[top][i] = temp * 2
                        top+=1
                    else:
                        top+=1
                        board[top][i] = temp

    elif dir == 1: # 하
        
        for i in range(N):
            down = N-1
            for j in range(N-2, -1, -1):
                if board[j][i]:
                    temp = board[j][i]
                    board[j][i] = 0
                    if board[down][i] == 0:
                        board[down][i] = temp
                    elif board[down][i] == temp:
                        board[down][i] = temp * 2
                        down-=1
                    else:
                        down-=1
                        board[down][i] = temp

    elif dir == 2: # 좌
        
        for i in range(N):
            left = 0
            for j in range(1,N):
                if board[i][j]:
                    temp = board[i][j]
                    board[i][j] = 0
                    if board[i][left] == 0:
                        board[i][left] = temp
                    elif board[i][left] == temp:
                        board[i][left] = temp * 2
                        left+=1
                    else:
                        left+=1
                        board[i][left] = temp
    else: # 우
        
        for i in range(N):
            right = N-1
            for j in range(N-2, -1, -1):
                if board[i][j]:
                    temp = board[i][j]
                    board[i][j] = 0
                    if board[i][right] == 0:
                        board[i][right] = temp
                    elif board[i][right] == temp:
                        board[i][right] = temp * 2
                        right-=1
                    else:
                        right-=1
                        board[i][right] = temp   

def dfs(total):
    global board, ans
    if total == 5:
        for i in range(N):
            for j in range(N):
                ans = max(ans, board[i][j])
        return
    temp_board = copy.deepcopy(board)
    for i in range(4):
        movemove(i)
        dfs(total+1)
        board = copy.deepcopy(temp_board)

ans = 0
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

dir_y, dir_x = [-1,1,0,0], [0,0,-1,1] # 상하좌우

dfs(0)
print(ans)