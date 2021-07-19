def go(f,b,k):
    if k<0 or k>9:
        return 0
    if b == n:
        if f == (1<<10)-1:
            return 1
        else:
            return 0
    
    if dp[f][b][k] != -1:
        return dp[f][b][k]

    dp[f][b][k] = 0

    if k == 0:
        dp[f][b][k] += go(f | (1<<(k+1)), b+1, k+1)
    elif k == 9:
        dp[f][b][k] += go(f | (1<<(k-1)), b+1, k-1)
    else:
        dp[f][b][k] += go(f | (1<<(k+1)), b+1, k+1)
        dp[f][b][k] += go(f | (1<<(k-1)), b+1, k-1)


    return dp[f][b][k]

mod = 1000000000
n = int(input())
ans = 0

dp = [[[-1]*11 for _ in range(101)] for _ in range(1<<11)]

for i in range(1,10):
    ans += go(1<<i, 1, i) # 비트 수(사용한 숫자 표현), 자릿 수, 마지막 수
    ans %= mod

print(ans)