from collections import deque

T = int(input())

for _ in range(T):
    n, k = map(int, input().split())
    time = [0] + list(map(int, input().split()))
    indegree = [0]*(n+1)
    s = [[] for _ in range(n+1)]
    dp = [0]*(n+1)
    for _ in range(k):
        u, v = map(int, input().split())
        s[u].append(v)
        indegree[v]+=1
        
    w = int(input())

    q = deque()
    for i in range(1, n+1):
        if indegree[i]==0:
            q.append(i)
            dp[i] = time[i]

    while q:
        cur = q.popleft()

        for i in s[cur]:
            indegree[i]-=1
            dp[i] = max(dp[cur]+time[i], dp[i])
            if indegree[i]==0:
                q.append(i)

    print(dp[w])
