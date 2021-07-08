n = int(input())

dp = [0] * 101
dp[2] = 2
dp[3] = 3
dp[4] = 4
dp[5] = 6
dp[6] = 9
dp[7] = 12
dp[8] = 16
dp[9] = 27

for i in range(10,n+1):
    for j in range(n+1):
        dp[i] = max(dp[i-j]*dp[j], dp[i])
dp[2] = 1
dp[3] = 2

print(dp[n])