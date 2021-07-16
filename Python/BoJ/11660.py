n, m = map(int, input().split())

s = []
dp = [[0]*(n+1) for _ in range(n+1)]

for _ in range(n):
    s.append(list(map(int,input().split())))
dp[0][0] = s[0][0]
for i in range(1,n):
    dp[0][i] = dp[0][i-1]+s[0][i]
    dp[i][0] = dp[i-1][0] + s[i][0]
    
for i in range(n):
    for j in range(n):
        dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1] - dp[i][j] + s[i][j]

for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    print(dp[x2][y2] - (dp[x1-1][y2] + dp[x2][y1-1] - dp[x1-1][y1-1]))
