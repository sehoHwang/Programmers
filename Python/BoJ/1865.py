import heapq
import copy
def bellmanFord():
    global isPossible

    for i in range(1, N+1):
        for j in range(1, N+1):
            for v, w in s[j]:
                if dp[v] > w+dp[j]:
                    dp[v] = w+dp[j]
                    if i==N:
                        isPossible = False

TC = int(input())
inf = 100000000

for _ in range(TC):
    N, M, W = map(int, input().split())
    s = [[] for _ in range(N+1)]
    dp = [inf]*(N+1)

    for _ in range(M):
        S, E, T = map(int, input().split())
        s[S].append([E,T])
        s[E].append([S,T])

    for _ in range(W):
        S, E, T = map(int, input().split())
        s[S].append([E,-T])
    
    isPossible = True

    bellmanFord()

    print("NO" if isPossible else "YES")