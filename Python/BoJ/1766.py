import heapq

n, m = map(int, input().split())

arr = [[] for _ in range(n+1)]
indegree = [0]*(n+1)
ans = []

for _ in range(m):
    A,B = map(int, input().split())
    arr[A].append(B)
    indegree[B]+=1


heap = []
for i in range(1,n+1):
    if indegree[i]==0:
        heapq.heappush(heap, i)

while heap:
    cur = heapq.heappop(heap)
    ans.append(str(cur))

    for nxt in arr[cur]:
        indegree[nxt]-=1
        if indegree[nxt] == 0:
            heapq.heappush(heap, nxt)

print(' '.join(ans))