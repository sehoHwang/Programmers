from collections import deque

n, e = map(int, input().split())

def dijkstra(start, s, dp):
    q = deque()
    q.append((start, 0))
    dp[start] = 0
    while q:
        node, w = q.popleft()
        for new_node, new_w in s[node]:
            if dp[new_node] > w+new_w:
                dp[new_node] = w+new_w
                q.append((new_node, dp[new_node]))

inf = 100000000
s = [[] for _ in range(n+1)]


dp1 = [inf]*(n+1)
dp2 = [inf]*(n+1)
dp3 = [inf]*(n+1)

for _ in range(e):
    a, b, c = map(int , input().split())
    s[a].append([b,c])
    s[b].append([a,c])

v1, v2 = map(int, input().split())

dijkstra(1, s, dp1)
dijkstra(v1, s, dp2)
dijkstra(v2, s, dp3)

if dp1[v1]>=inf or dp2[v2]>=inf or dp3[n]>=inf or dp1[v2]>=inf or dp3[v1]>=inf or dp2[n]>=inf:
    print(-1)
else:
    min_ = min(dp1[v1]+dp2[v2]+dp3[n], dp1[v2]+dp3[v1]+dp2[n])
    print(min_)



