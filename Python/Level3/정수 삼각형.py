def solution(triangle):
    answer = 0
    
    N = len(triangle)
    dp = [[0]*i for i in range(1, len(triangle)+1)]
    dp[0][0] = triangle[0][0]
    for i in range(len(triangle)-1):
        for j in range(len(triangle[i])):
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+triangle[i+1][j])
            if j+1<N:
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+triangle[i+1][j+1])
                              
    return max(dp[N-1])