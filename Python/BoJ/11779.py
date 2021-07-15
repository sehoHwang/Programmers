import heapq, copy
heap = []
def dijkstra(first, end):
    answer = [first]
    count = 0
    heapq.heappush(heap, (0,first, 1, answer))
    dp[start] = 0
    while heap:
        w, v, cnt, visited = heapq.heappop(heap)
        if dp[v] < w:
            continue
        for new_v, new_w in s[v]:
            if dp[new_v] > w+new_w:
                dp[new_v] = w+new_w
                temp_visited = copy.deepcopy(visited)
                temp_visited.append(new_v)
                if new_v == end:
                    answer = temp_visited
                    count = cnt+1
                heapq.heappush(heap, (dp[new_v], new_v, cnt+1, temp_visited)) 
    return answer, count

inf = 100000000
n = int(input())
m = int(input())
s = [[] for _ in range(n+1)]
dp = [inf]*(n+1)
for _ in range(m):
    a,b,c = map(int, input().split())
    s[a].append([b,c])

start, end = map(int, input().split())

answer, count = dijkstra(start,end)
print(dp[end])
print(count)
print(' '.join(map(str,answer)))