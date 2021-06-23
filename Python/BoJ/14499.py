N, M, y, x, K = map(int, input().split())

board = []

for _ in range(N):
    board.append(list(map(int, input().split())))

move = list(map(int, input().split()))

dy = [0, 0, -1, 1] # 동, 서, 북, 북
dx = [1, -1, 0, 0]
dice = [0 for _ in range(6)]

d_num = [0,0,0,0,0,0]
dice_num = 1
for m in move:
    nxt_y, nxt_x = y+dy[m-1], x+dx[m-1]
    if nxt_y<0 or nxt_y>=N or nxt_x<0 or nxt_x>=M:
        continue
    
    y, x = nxt_y, nxt_x
    if m == 1:
        dice[0], dice[2], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[2]
    elif m == 2:
        dice[0], dice[2], dice[3], dice[5] = dice[2], dice[5], dice[0], dice[3]
    elif m == 3:
        dice[0], dice[1], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[1]
    else:
        dice[0], dice[1], dice[4], dice[5] = dice[1], dice[5], dice[0], dice[4]

    print(dice[0])

    if board[y][x] == 0:
        board[y][x] = dice[5]
    else:
        dice[5] = board[y][x]
        board[y][x] = 0
    