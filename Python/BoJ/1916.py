import heapq

def dijkstra(start):
    heapq.heappush(heap, (0, start))
    dp[start] = 0
    while heap:
        w, v = heapq.heappop(heap)
        if dp[v]<w:
            continue
        for new_v, new_w in bus[v]:
            if dp[new_v] > w+new_w:
                dp[new_v] = w+new_w
                heapq.heappush(heap, (dp[new_v], new_v))

heap = []

N = int(input())
M = int(input())
inf = 100000000
dp = [inf]*(N+1)
bus = [[] for _ in range(N+1)]

for _ in range(M):
    s, e, d = map(int, input().split())
    bus[s].append([e,d])

start, end = map(int, input().split())

dijkstra(start)
print(dp[end])
