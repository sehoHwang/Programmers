from collections import defaultdict, deque
import sys
input = sys.stdin.readline # 중요!!!!, 입력 속도가 느리면 통과 불가능.
def bfs(s):
    rt = 0
    q = deque()
    q.append(s)
    visit = [0 for _ in range(N+1)]
    visit[s] = 1
    while q:
        cur = q.popleft()
        rt+=1
        for v in computers[cur]:
            if not visit[v]:
                visit[v] = 1
                q.append(v)
    return rt


N,M = map(int, input().split())
ans = 0
result = []
computers = defaultdict(list)
for _ in range(M):
    i, j = map(int, input().split())
    computers[j].append(i)
print(computers)
print(G)
for i in range(1, N+1):
    if computers[i]:
        tmp = bfs(i)
        if ans <= tmp:
            if ans < tmp:
                retult = []
            ans = tmp
            result.append(i)
print(*result)


        