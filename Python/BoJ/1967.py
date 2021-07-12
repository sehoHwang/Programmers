import heapq, copy
n = int(input())
heap = []
def dijkstra(start, new_dp):
    max_node, max_w = 0, 0
    heapq.heappush(heap, (0, start))
    new_dp[start] = 0
    while heap:
        w, v = heapq.heappop(heap)
        if new_dp[v] < w:
            continue
        for new_v, new_w in graph[v]:
            if new_dp[new_v] > w+new_w:
                new_dp[new_v] = w+new_w
                heapq.heappush(heap, (new_dp[new_v], new_v))
                if new_dp[new_v] > max_w:
                    max_w = new_dp[new_v]
                    max_node = new_v
    return max_node, new_dp

inf = 100000000
graph = [[] for _ in range(n+1)]
dp = [inf]*(n+1)
temp_dp = copy.deepcopy(dp)
temp_dp2 = copy.deepcopy(dp)
for _ in range(n-1):
    v1, v2, w = map(int, input().split())
    graph[v1].append([v2,w])
    graph[v2].append([v1,w])

far_node1, return_dp1 = dijkstra(1, temp_dp)
far_node2, return_dp2 = dijkstra(far_node1, temp_dp2)

print(return_dp2[far_node2])
