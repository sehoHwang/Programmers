from collections import defaultdict, deque

def dijkstra(start, dp, s):
    q = deque()
    q.append((start, 0))
    dp[start] = 0
    while q:
        node, w = q.popleft()
        #if dp[node] < w:
        #    continue
        for new_node, new_w in s[node]:
            if dp[new_node] > w+new_w:
                dp[new_node] = w+new_w
                q.append((new_node, dp[new_node]))

n, m, x = map(int, input().split())
inf = 100000000
s = [[] for _ in range(n+1)]
s_r = [[] for _ in range(n+1)]
dp = [inf for _ in range(n+1)]
dp_r = [inf for _ in range(n+1)]

for _ in range(m):
    start, end, dis = map(int, input().split())
    s[start].append([end,dis])
    s_r[end].append([start,dis])

dijkstra(x, dp, s)
dijkstra(x, dp_r, s_r)

max_ = 0
for i in range(1,n+1):
    max_ = max(max_, dp[i]+dp_r[i])
print(max_)