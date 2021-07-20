def check(idx):
    i,j = idx//n, idx%n

    for d in range(4):
        x, y = i+dx[d], j+dy[d]
        while 0<=x<n and 0<=y<n:
            if visited[x*n+y]:
                return False
            x+=dx[d]
            y+=dy[d]
    
    return True


def go(idx, c, cnt):
    if idx >= n*n:
        return
    ans[c] = max(ans[c], cnt)

    x, y = idx//n, idx%n
    j = y
    for i in range(x, n):
        while j<n:
            if not visited[i*n+j] and board[i][j]==1 and check(i*n+j):
                visited[i*n+j] = True
                go(i*n+j, c, cnt+1)
                visited[i*n+j] = False
            
            j+=2
        
        j = (c+1)%2 if i%2 == 0 else c


n = int(input())

board = []
visited = [False]*(n**2)
ans = [0,0]
dx = [1, 1, -1, -1]
dy = [1, -1, 1, -1]

for _ in range(n):
    board.append(list(map(int, input().split())))

go(0, 0, 0)
go(1, 1, 0)

print(sum(ans))