from collections import deque
import sys
import heapq

input = sys.stdin.readline
heap = []
def dijkstra(start):
    heapq.heappush(heap, (0,start))
    dp[start] = 0
    while heap:
        w, v = heapq.heappop(heap)
        if dp[v] < w:
            continue
        for new_v, new_w in s[v]:
            if dp[new_v] > w+new_w:
                dp[new_v] = w+new_w
                heapq.heappush(heap, (dp[new_v],new_v))

V, E = map(int, input().split())
k = int(input())
s = [[] for _ in range(V+1)]
inf = 100000000
dp = [inf]*(V+1)

for _ in range(E):
    u, v, w = map(int, input().split())
    s[u].append([v,w])

dijkstra(k)

for i in range(1, V+1):
    if dp[i] == inf:
        print('INF')
    else:
        print(dp[i])